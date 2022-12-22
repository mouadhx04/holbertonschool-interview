#include <stdlib.h>
#include <stdio.h>
#include "substring.h"

/**
 * find_substring - finds all the substrings containing a list of words
 * @s: the string to scan
 * @words: the array of words all substrings
 * @nb_words: the number of elements in the array
 * @n: the address at which to store the number of elements
 * Return: return an allocated array
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *ret;
	int s_len = 0;
	int w_len = 0;
	int i;

    /* Initialize n */
	*n = 0;

    /* Null Check inputs */
	if (s == NULL || words == NULL || *words == NULL || nb_words == 0)
		return (NULL);

    /* Calculate lenth of s and words */
	for (i = 0; s[i] != '\0'; i++)
		s_len++;
	for (i = 0; words[0][i] != '\0'; i++)
		w_len++;

    /* malloc return and Null Check*/
	ret = malloc(sizeof(int) * s_len);
	if (ret == NULL)
		return (NULL);

    /* iterate through s to find matches*/
	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (match_search(s + i, words, nb_words, w_len))
		{
			ret[*n] = i;
			*n = *n + 1;
		}
	}
    /* if no mathes, free and return NULL*/
	if (*n == 0)
	{
		free(ret);
		return (NULL);
	}

	return (ret);
}

/**
 * match_search - find full match
 * @s: passed string
 * @words: passed array of words
 * @nb_words: length of array words
 * @word_ln: the length of each word
 * Return: 1 if match of substring made of 'words' exists, or 0
 */
int match_search(char const *s, char const **words, int nb_words, int word_ln)
{
	int *comp;
	int comp_len = 0;
	int found = 0;
	int match = 1;
	int j, k, l;
	int m;

	comp = malloc(sizeof(int) * nb_words);
	for (l = 0; l < nb_words; l++)
		comp[l] = -1;
	for (j = 0; j < nb_words; j++)
	{
		found = 0;
		for (k = 0; k < nb_words; k++)
		{
			m = in_string(comp, comp_len, k);
			if (m && string_match((s + (j * word_ln)), words[k]))
			{
				comp[comp_len] = k;
				comp_len++;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			match = 0;
			break;
		}
	}
	free(comp);
	return (match);
}

/**
 * string_match - match substring of str
 * @str: a string
 * @word: an array of words
 * Return: 1 if word is a substring of str, or 0
 */
int string_match(char const *str, char const *word)
{
	int i = 0;

	for (i = 0; *(word + i) != '\0'; i++)
	{
		if (*(str + i) != *(word + i))
			return (0);
	}
	return (1);
}

/**
 * in_string - return 1 if 'q' not in array 'arr'
 * @arr: an array of ints
 * @len: the length of arr
 * @q: the value to check for
 * Return: 1 if value not found, else 0
 */
int in_string(int *arr, int len, int q)
{
	int i  = 0;

	for (i = 0; i < len; i++)
	{
		if (arr[i] == q)
			return (0);
	}
	return (1);
}
