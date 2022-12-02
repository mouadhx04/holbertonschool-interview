#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @s1: string to compare against
 * @s2: string to compare
 *
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == *s2 && *s1 != '\0')
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	if (*s1 == *s2)
	{
		return (1);
	}
	if (*s2 == '*' && *(s2 + 1) != *s1 && *(s2 + 1) != '*')
	{
		return (wildcmp(s1 + 1, s2));
	}
	if (*s2 == '*' && *(s2 + 1) != *s1 && *(s2 + 1) == '*')
	{
		return (wildcmp(s1, s2 + 1));
	}
	if (*s2 == '*' && wildcmp(s1, s2 + 1) == 0)
	{
		return (wildcmp(s1 + 1, s2));
	}
	if (*s2 == '*' && wildcmp(s1, s2 + 1) == 1)
	{
		return (1);
	}
	return (0);
}
