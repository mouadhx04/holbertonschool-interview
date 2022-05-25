#include "lists.h"

/**
* recurse_list - Compares 1st and last node, then 2nd last and 2nd, etc
*
* @left: Keeps track of left side of list
*
* @right: Keeps track of nodes on right
*
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/

int recurse_list(listint_t **left, listint_t *right)
{
	int result;


	/* Base case for empty list*/
	if (right == NULL)
	{
		return (1);
	}

	/* Check values at left and right then 2nd node & 2nd to last, etc */
	result = recurse_list(left, right->next) && (*left)->n == right->n;

	/* Point left to next node */
	*left = (*left)->next;

	return (result);
}

/**
* is_palindrome - Checks if LL is a palindrome
*
* @head: Double pointer to head of list
*
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/

int is_palindrome(listint_t **head)
{
	listint_t *deref = *head;

	return (recurse_list(&deref, deref));
}
