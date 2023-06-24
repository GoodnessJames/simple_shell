#ifndef SHELL_H
#define SHELL_H

/*
 * File: main.h
 * Desc: This file contains prototypes for all the functions & struct
 *		 required for the project - (0x16. C - Simple Shell)
 */

/* Standard C Library Headers */
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

/* External Variable Declaration */
extern char **environ;

/**
 * struct list_path - A struct type defining a linked list
 * @dir: The directory path
 * @next: A pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *next;
} list_path;

/**
 * struct builtins - A struct type defining builtin commands
 * @name: The command name
 * @fpt: A function pointer to the builtin command functions
 */
typedef struct builtins
{
	char *name;
	void (*fpt)(char **);
} builtins;

/* Function Prototypes in File: checker.c */
void check_input(void);
void check_EOF(int len, char *buffer);
void check_sig(int sig);
void(*checkbuiltin(char **cmd))(char **av);

/* Function Prototypes in File: environ.c */
char *_getenv(const char *var);
void _printenv(char **av);
void _setenv(char **av);
void _unsetenv(char **av);

/* Function Prototype in File: execute.c */
void execute(char **args);

/* Function Prototype in File: exit.c */
void shellexit(char **av);

/* Function Prototypes in File: linkpath.c */
list_path *linkpath(char *path);
list_path *add_endnode(list_path **head, char *path);
void free_list(list_path *head);
char *findpath(char *cmd, list_path *head);

/* Function Prototypes in File: memory_handlers.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_av(char **av);

/* Function Prototypes in File: str_func1.c */
int _strlen(char *s);
char *_strdup(char *str);
char *_strconcat(char *cmd, char *delim, char *value);
int _putchar(char c);
void _puts(char *str);

/* Function Prototypes in File: str_func2.c */
int _atoi(char *str);

/* Function Prototypes in File: strtok.c */
char **splitStr(char *str, const char *delim);

#endif
