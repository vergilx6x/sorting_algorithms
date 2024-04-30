#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * swap_nodes - Sorts a doubly linked list.
 * @list: A pointer to the head of the list.
 * @node_1: First node to swap
 * @node_2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;
	if (node_2->next != NULL)
		node_2->next->prev = *node_1;
	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;
	if ((*node_1)->prev != NULL)
		(*node_1)->prev->next = node_2;
	else
		*list = node_2;
	(*node_1)->prev = node_2;
	*node_1 = node_2->prev;
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
