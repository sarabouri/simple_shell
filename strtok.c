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
		if (delim_check(lm[x], delimiter) == 0)
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
/**
 * parse_input - this function is used to parse
 * the input command line
 * @cmd: command of input tha user entered to parse
 * Return: array of parsed characters.
 */
char **parse_input(char *cmd)
{
	char **tokens;
	char *token;
	int x, buffersize = BUFSIZE;

	if (cmd == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffersize);
	if (!tokens)
	{
		perror("hsh"); /* need to verifythis one */
		return (NULL);
	}

	token = _strtok(cmd, "\n ");
	for (x = 0; token; x++)
	{
		tokens[x] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[x] = NULL;

	return (tokens);
}
