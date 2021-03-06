#ifndef SHELL2_H
#define SHELL2_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#define BUFF_SIZE 1024
#define PROMPT "$ "
/**
 * struct dirset - linked list of set of directories
 * @dir: pointer to string of the directory
 * @next: pointer to the next node
 */
typedef struct dirset
{
	char *dir;
	struct dirset *next;
} dirset_t;
dirset_t *add_node_end(dirset_t **head, const char *dir);
dirset_t *path_link(void);
int _strlen(const char *s);
char **tokenizer(char *line);
char **findpath(char **tok_args);
char *_strdup(const char *str);
char *pathcat(char *buff, char *dir, char **tok_args);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
void free_path(dirset_t *head);
#endif
