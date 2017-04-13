#include "shell2.h"

/**
 * add_node_end - function to add node to end of list
 * @head: double pointer passed
 * @dir: const char string passed
 * Return: address of new element or NULL if failed
 */
dirset_t *add_node_end(dirset_t **head, const char *dir)
{
	list_t *endnode;
	list_t *travelnode;

	if (head == NULL)
		return (NULL);

	endnode = malloc(sizeof(dirset_t));
	travelnode = malloc(sizeof(dirset_t));

	if (*head == NULL)
	{
		*head = endnode;
	}
	if (travelnode == NULL)
		return (NULL);
	travelnode = *head;

	while (travelnode->next != NULL)
		travelnode = travelnode->next;

	travelnode->next = endnode;
	endnode->dir = _strdup(dir);
	endnode->next = (NULL);

	return (endnode);
}
