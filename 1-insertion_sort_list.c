#include "sort.h"

/**
 *insertion_sort_list - sorts a doubly linked list of integers in
 *                      ascending order using the Insertion sort algorithm
 *@list: double ptr to the head of linked list
 *Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *insertNode, *nextInsert;

	if (list == NULL || *list == NULL)
		return;
	insertNode = (*list)->next;
	while (insertNode != NULL)
	{
		nextInsert = insertNode->next;
		while (insertNode->prev != NULL &&
		       insertNode->prev->n > insertNode->n)
		{
			insertNode->prev->next = insertNode->next;
			if (insertNode->next != NULL)
				insertNode->next->prev = insertNode->prev;
			insertNode->next = insertNode->prev;
			insertNode->prev = insertNode->next->prev;
			insertNode->next->prev = insertNode;
			if (insertNode->prev == NULL)
				*list = insertNode;
			else
				insertNode->prev->next = insertNode;
			print_list(*list);
		}
		insertNode = nextInsert;
	}
}
