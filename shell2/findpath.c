#include"shell2.h"
/**
 * findpath - function to create full path argument
 * @tok_args: getline input that has been tokenized
 * Return: new argument with the completed path
 */
char **findpath(char **tok_args)
{
	dirset_t *head;
	char *buff;
	char *buffcopy;

	head = path_link();

	while(head != NULL)
	{
/** is this a safe way to free? **/
		buff = malloc(sizeof(char) * (_strlen(tok_args[0]) + _strlen(head->dir) + 2));
		if(buff == NULL)
			return(0);
		pathcat(buff, head->dir, tok_args); /**put in freakin concat file**/
		if(access(buff, X_OK) == 0)
		{
/**lacking confidence on how accurate this is **/
			buffcopy = _strdup(buff);
			tok_args[0] = buffcopy;
			free(buff);
			/**free linked list function to call here**/
			return(tok_args);
		}
		else
		{
			free(buff);
			head = head->next;
		}
	}
/**free linked list function to call here **/
	return(tok_args);
}
/**
 *
 *
 *
 */
dirset_t *path_link(void)
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
