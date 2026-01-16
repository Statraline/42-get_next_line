/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:21:26 by srichard          #+#    #+#             */
/*   Updated: 2025/12/03 15:11:07 by srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash, char *buffer)
{
	ssize_t	b_read;
	char	*temp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

static char	*extract_line(char *line_buffer)
{
	char	*stash;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == 0 || line_buffer[i + 1] == 0)
		return (NULL);
	stash = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i - 1);
	if (*stash == 0)
	{
		free(stash);
		stash = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line_buffer;
	static char	*stash;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line_buffer = read_and_stash(fd, stash, buffer);
	free(buffer);
	buffer = NULL;
	if (!line_buffer)
		return (NULL);
	stash = extract_line(line_buffer);
	return (line_buffer);
}
