#include"shell2.h"
/**
 * free_path - function to free list
 * @head: passed parameter pointer of struct
 * Return: void
 */
void free_path(dirset_t *head)
{
	dirset_t *traveler;

	while (head != NULL)
	{
		traveler = head;
		head = head->next;
		free(traveler->dir);
		free(traveler);
	}
}
