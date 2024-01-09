#include "main.h"

/**
 * _realloc - function used to realloc memory
 * @o_size: old size of poiter p
 * @n_size: new size of poiter p
 * @p: poiter
 * Return: poiter of reallocated memory
 */
void *_realloc(void *p, unsigned int o_size, unsigned int n_size)
{
	void *n_p;

	if (n_size == o_size)
		return (p);
	if (n_size == 0 && p)
	{
		free(p);
		return (NULL);
	}
	n_p = malloc(n_size);
	if (n_p == NULL)
		return (NULL);
	if (p == NULL)
	{
		_fill_an_array(n_p, '\0', n_size);
		free(p);
	}
	else
	{
		_memcpy(n_p, p, o_size);
		free(p);
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
 * @a: void array
 * @element: integer
 * @L: Length integer
 * Return:void poiter
 */
void *_fill_an_array(void *a, int element, size_t L)
{
	char *p = a;
	size_t j;

	for (j = 0; j < L; j++)
	{
		*p = (char)element;
		/*p;*/
	}

	return (a);
}
/**
 * free_koulshi - function that frees all
 * @command: array of poiter
 * @ligne: character poiter
 */
void free_koulshi(char **command, char *ligne)
{
	free(command);
	free(ligne);
	command = NULL;
	ligne = NULL;
}
/**
 * free_enviro - function that frees environment variable array
 * @enviro: environment variable
 *  Return: void.
 */
void free_enviro(char **enviro)
{
	int j;

	for (j = 0; enviro[j]; j++)
	{
		free(enviro[j]);
	}

}
