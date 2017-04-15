#include "shell2.h"

/**
 * add_node_end - function to add node to end of list
 * @head: double pointer passed
 * @dir: const char string passed
 * Return: address of new element or NULL if failed
 */
dirset_t *add_node_end(dirset_t **head, const char *dir)
{
	dirset_t *new_node, *temp;
    
	new_node = malloc(sizeof(dirset_t));
    
	if (new_node == NULL)
        return (NULL);

    new_node->dir = _strdup(dir);
    new_node->next = NULL;

    if (!*head)
    {
        *head = new_node;
    }
    else
    {
        temp = *head;

        while (temp->next)
            temp = temp->next;

        temp->next = new_node;
    }

    return (new_node);
}
