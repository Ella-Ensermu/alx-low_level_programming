#include "lists.h"
#include<stdlib.h>

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 * Return: no return value
 */

void free_listint(listint_t *head)
{
	listint_t *freenode;

	while (head)
	{
		freenode = head->next;
		free(head);
		head = freenode;
	}
}
