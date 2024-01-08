#include "main.h"

/**
 * _strchr - function that locates a character in a string
 * @s: string
 * @a: character
 * Return: the pointer to the 1st occurence of the character a.
 */
char *_strchr(char *s, char a)
{
	unsigned int j = 0;

	for (; *(s + j) != '\0'; j++)
		if (*(s + j) == a)
			return (s + j);
	if (*(s + j) == a)
		return (s + j);
	return ('\0');

}
/**
 * _strncmp - this function compares l characters of the str1 AND str2
 * @str1: 1st string
 * @str2: 2nd string
 * @l: number of characters to compare
 * Return: 0 if the strings match otherwise 1.
 */
int _strncmp(const char *str1, const char *str2, size_t l)
{
	size_t j;

	if (str1 == NULL)
		return (-1);
	for (j = 0; j < l && str2[j]; j++)
	{	
		if (str1[j] != str2[j])
		{
			return (1);
		}
	}
	return (0);
}
