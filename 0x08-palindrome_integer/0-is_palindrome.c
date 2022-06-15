#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - check palindrome
 * @n: unsigned long
 * Return: integer 1 or 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long num, val = 0;

	num = n;

	while (num != 0)
	{
		val = val * 10;
		val = val + num % 10;
		num = num / 10;
	}
	if (n == val)
		return (1);
	else
		return (0);
}
