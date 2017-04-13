#ifndef SHELL2_H
#define SHELL2_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define BUFF_SIZE 1024
#define PROMPT "$ "
/**
 * struct dirset - linked list of set of directories
 * @dir: pointer to string of the directory
 * @next: pointer to the next node
 */
typdef struct dirset
{
	char *dir;
	struct dirset *next;
} dirset_t;
dirset_t add_new_node(dirset_t **head, const char *dir);
dirset_t path_link(void);
int _strlen(const char *s);
char **tokenizer(char *line);
char **new_arg(char **tok_args);
char *_strdup(char *str);
char *path_cat(char *dest, char *src);
#endif
