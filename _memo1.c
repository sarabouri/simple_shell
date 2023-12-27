#include "main.h"

/**
 * _realloc - function used to realloc memory
 * @o_size: old size of poiter p
 * @n_size: new size of poiter p
 * @p: poiter
 * Return: poiter of reallocated memory
 */

void *_realloc(char *p, size_t o_size, size_t n_size)
{
	if (n_size == o_size)
		return (p);
	if (n_size == 0 && p)
	{
		free(p);
		return (NULL);
	}
	char *n_p = malloc(n_size);

	if (n_p == NULL)
		return (NULL);
	if (p != NULL)
	{
		_memcpy(n_p, p, o_size);
		free(p);
	}
	else
	{
		_fill_an_array(n_p, '\0', n_size);
	}
	return (n_p);
}
/**
 *_memcpy - this function copies memory area
 * @d: destination memory area
 * @s: source memry area
 * @F: filled bytes
 * Return: poiter to d
 */
char *_memcpy(char *d, char *s, unsigned int F)
{
	unsigned int j;

	for (j = 0; j < F; j++)
		*(d + j) = *(s + j);

	return (d);
}
/**
 * _fill_an_array - Fill an by constant byte
 * @a: void
 * @element: integer
 * @L: Length integer
 * Return:void poiter
 */
void *_fill_an_array(void *a, int element, size_t L)
{
	char *p = a;

	for (size_t j = 0; j < L; j++)
	{
		*p = (char)element;
		p;
	}

	return (a);
}

