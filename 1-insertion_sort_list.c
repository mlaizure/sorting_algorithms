#include "sort.h"

/**
 * insertion_sort_list - sorts double linked list of ints in ascending order
 * using the Insertion sort algorithm
 * @list: head of doubly linked list
 * Return: none
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *origbig, *origsmall, *newbig, *newsmall;
	listint_t *first, *last, *check;

	if (!list || !*list)
		return;
	if (!(*list)->next)
		return;
	while (1)
	{
		for (node = *list; node->next != NULL; node = node->next)
			if (node->n > node->next->n)
			{
				origbig = node, origsmall = node->next;
				first = node->prev, last = origsmall->next;
				newbig = origbig, newsmall = origsmall;
				newbig->prev = newsmall;
				newsmall->next = newbig;
				if (first)
				{
					first->next = newsmall;
					newsmall->prev = first;
				}
				else
					(*list = newsmall)->prev = NULL;
				if (last)
				{
					newbig->next = last;
					last->prev = newbig;
				}
				else
					newbig->next = NULL;
				print_list(*list);
				break;
			}
		check = *list;
		while (check->next && check->n <= check->next->n)
			check = check->next;
		if (!check->next)
			break;
	}
}
