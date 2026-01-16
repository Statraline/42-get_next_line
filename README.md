# 42 - Get Next Line

![Langage](https://img.shields.io/badge/Language-C-blue)
![Note](https://img.shields.io/badge/Score-125%2F100-brightgreen)
![Statut](https://img.shields.io/badge/Status-Finished-success)

## 💡 Description

**Get Next Line** est un projet fondamental du cursus 42. Il consiste à programmer une fonction qui retourne une ligne lue depuis un descripteur de fichier (file descriptor).

Ce projet introduit le concept de **variables statiques** en C et permet de comprendre la gestion des buffers et les fuites mémoires.

## 🛠️ Fonctionnalités (Bonus inclus)
* Lecture ligne par ligne depuis un fichier ou l'entrée standard.
* **Gestion de multiples descripteurs de fichiers** (lecture alternée sur plusieurs fichiers sans perdre le fil).
* Utilisation d'une seule variable statique.
* Aucune fuite mémoire (Valgrind approved).

## 🚀 Utilisation

 Prototype : `char *get_next_line(int fd);`

Compiler avec la taille du buffer souhaitée :
```bash
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
