#ifndef _SUBSTRING_H_
#define _SUBSTRING_H_

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int match_search(char const *s, char const **words, int nb_words, int word_ln);
int string_match(char const *str, char const *word);
int in_string(int *arr, int len, int q);

#endif
