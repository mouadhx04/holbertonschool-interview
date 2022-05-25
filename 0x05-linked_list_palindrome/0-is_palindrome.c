#include "lists.h"

/**
* is_palindrome - check if list plaindrome
* @head: head
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	listint_t *temp, *node;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	node = *head;
	while (node->next)
	{
		node = node->next;
	}
	temp = *head;
	while (node >= temp)
	{
		if (temp->n == node->n)
		{
			temp = temp->next;
			node -= 2;
		}
		else
			return (0);
	}
	return (1);
}
