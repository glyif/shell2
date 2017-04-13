#include"shell2.h"
/**
 *
 *
 *
 */
char **new_arg(char **tok_args)
{
	list_t tmp;
	char *buff;
	char *buffcopy;

	path_linklist();
	tmp = head;

	while(tmp != NULL)
	{
		buff = malloc(sizeof(char) * (_strlen(tok_args[0] + _strlen(tmp->dir + 2))));
		if(buff == NULL)
			exit;
		if(access(buff, F_OK) == 0)
		{
			buffcopy = _strdup(buff);
			tok_args[0] = buffcopy;
			free(buff);
			return(tok_args[0]);
		}
		else
		{
			free(buff);
			tmp = tmp->next;
		}
	}
}
/**
 *
 *
 *
 */
dirset_t path_linklist(void)
{
	dirset_t *head;
	char *full_path;
	char *dir;

	head = NULL;
	full_path = _getenv("PATH");
	dir = strtok(full_path, ":");
	while(full_path != NULL)
	{
		if(dir == NULL)
			break;
		if (dir != NULL)
			add_node_end(&head, dir);
		dir = strtok(NULL, ":");
	}
	return(head);
}
