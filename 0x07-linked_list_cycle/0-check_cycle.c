#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to the head of the linked list
 * Return: 1 if there is a cycle, otherwise 0.
 **/
int check_cycle(listint_t *list)
{
	listint_t *s = list;
	listint_t *f = list;

	while (f && f->next)
	{
		s = s->next;
		f = f->next->next;
		if (s == f)
			return (1);
	}
	return (0);
}
