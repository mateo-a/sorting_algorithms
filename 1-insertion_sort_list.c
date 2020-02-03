#include "sort.h"
/**
 *  swap - function to swap values in a list
 *  @current: node to swap
 */
void swap(listint_t *current)
{
	listint_t *pre_prev_node, *prev_node, *next_node;

	if (current->prev == NULL)
		return;
	prev_node = current->prev;
	pre_prev_node = prev_node->prev;
	next_node = current->next;
	if (pre_prev_node != NULL)
		pre_prev_node->next = current;
	current->prev = pre_prev_node;
	current->next = prev_node;
	prev_node->prev = current;
	prev_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = prev_node;
}
/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 *  @list: doubly linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		if (current->prev->n > current->n)
		{
			temp = current->next;
			while (current->prev != NULL)
			{
				if (current->n < current->prev->n)
				{
					swap(current);
					while ((*list)->prev != NULL)
						(*list) = (*list)->prev;
					print_list(*list);
				}
				else
					break;
			}
			current = temp;
		}
		else
			current = current->next;
	}
}
