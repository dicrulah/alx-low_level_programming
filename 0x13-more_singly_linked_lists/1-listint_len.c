#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked lists
 * @head: linked list of type listint_t to traverse
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *head)
{
	size_t c = 0;

	while (head)
	{
		c++;
		head = head->next;
	}

	return (c);
}
