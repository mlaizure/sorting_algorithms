#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list, *origbig, *origsmall, *newbig, *newsmall, *first, *last, *check;

	while (1)
	{
		for (node = *list; node->next != NULL; node = node->next)
		{
			if (node->n > node->next->n)
			{
				origbig = node;
				origsmall = node->next;
				first = node->prev;
				last = origsmall->next;

				newbig = origbig;
				newsmall = origsmall;

				newbig->prev = newsmall;
				newsmall->next = newbig;

				if (first)
				{
					first->next = newsmall;
					newsmall->prev = first;
				}
				else
				{
					newsmall->prev = NULL;
					*list = newsmall;
				}
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
		}
		check = *list;
		while (check->next && check->n < check->next->n)
			check = check->next;
		if (!check->next)
			break;
	}
}
