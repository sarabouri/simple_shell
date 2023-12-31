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
