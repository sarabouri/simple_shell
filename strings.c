#include "main.h"

/**
 * _strcat - function commutes strings
 * @d: parameter poiter to a character
 * @s: parameter poiter to a character
 * Return: returns the value of d.
 */

char *_strcat(char *d, char *s)
{
	int x = 0;
	int y = 0;

	while (d[x] != '\0')
	{
		x++;
	}

	while (s[y] != '\0')
	{
		d[x] = s[y];
		y++;
		x++;
	}
	d[x] = '\0';
	return (d);
}
/**
 * _strdup - function that returns a poiter to a newly allocated spce in memo
 * @s: string
 *  Return: it returns an array of characters.
 */
char *_strdup(char *s)
{
	size_t l, j;
	char *s2;

	l = _strlen(s);
	s2 = malloc(sizeof(char) * (l + 1));
	if (!s2)
	{
		return (NULL);
	}
	for (j = 0; j <= l; j++)
	{
		s2[j] = s[j];
	}

	return (s2);
}
/**
 * _strcmp - compares two strings
 * @str1: first string.
 * @str2: second string.
 * Return: 0 if the two strings are equal
 * another number if not equal
 */
int _strcmp(char *str1, char *str2)
{
	int x = 0, O = 0;

	while (O == 0)
	{
		if ((*(str1 + x) == '\0') && (*(str2 + x) == '\0'))
			break;
		O = *(str1 + x) - *(str2 + x);
		x++;
	}
	return (O);
}

/**
 * _strlen - this function returns the length of a string
 * @str: string of the input
 * Return: it returns length of str
 */
int _strlen(char *str)
{
	int a;

	for (a = 0; str[a] != '\0'; a++)
	{

	}
	return (a);
}

/**
 * _strcpy - this function copies string
 * @d: destination string
 * @s: source string
 * Return: the function returns the destination string
 */
char *_strcpy(char *d, char *s)
{
	int x;

	x = 0;

	while (s[x])
	{
		d[x] = s[x];
		x++;
	}
	d[x] = '\0';
	return (d);
}
