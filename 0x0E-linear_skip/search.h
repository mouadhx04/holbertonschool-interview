#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>
#include <stdio.h>
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_t
{
	int n;
	size_t index;
	struct skiplist_t *next;
	struct skiplist_t *express;
} skiplist_t;

skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
