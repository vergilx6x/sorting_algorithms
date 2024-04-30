#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list.
 * @list: A pointer to the head of the list.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *key, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (key = (*list)->next;  key != NULL; key = temp)
	{
		temp = key->next;
		insert = key->prev;
		while (insert != NULL && key->n < insert->n)
		{
			swap_nodes(list, &insert, key);
			print_list(*list);
		}
	}
}
