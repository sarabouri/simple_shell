#include "main.h"
/**
 * _strtok - function that takes a string and split it into tokens
 * @s: a string
 * @delimiter: delimiter
 *  Return: it returns NULL or poiter to the next value
 */

char *_strtok(char *s, const char *delimiter)
{
	static char *lm;
	static char *n;
	unsigned int x;

	if (s != NULL)
		n = s;
	lm = n;
	if (lm == NULL)
		return (NULL);
	for (x = 0; lm[x] != '\0'; x++)
	{
		if (delim_check(lm[i], delimiter) == 0)
			break;
	}
	if (n[x] == '\0' || n[x] == '#')
	{
		n = NULL;
		return (NULL);
	}
	lm = n + x;
	n = lm;
	for (x = 0; n[x] != '\0'; x++)
	{
		if (delim_check(n[x], delimiter) == 1)
			break;
	}
	if (n[x] == '\0')
		n = NULL;
	else
	{
		n[x] = '\0';
		n = n + x + 1;
		if (*n == '\0')
			n = NULL;
	}
	return (lm);
}
/**
 * delim_check - this function checkes if character matches
 * any other character
 * @a: the character to check
 * @s: the String to check
 *  Return: on success 1 otherways 0.
 */
unsigned int delim_check(char a, const char *s)
{
	unsigned int x;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (a == s[x])
			return (1);
	}
	return (0);
}
