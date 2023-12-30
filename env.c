#include "main.h"

/**
 * com_path - Search in PATH for executable command
 * @com: parsed input
 * Return: 1 f 0 s
*/
int com_path(char **com)
{
	int stat buff;
	char *path, *compath, *value;

	path = _getenv("PATH");
	value = _strtok(path, ":");

	do {
		compath = _build(com, value);
		if (stat(compath, &buff) == 0)
		{
			*com = _strdup(compath);
			free(compath);
			free(path);
			return (0);
		}
		free(compath);
		value = _strtok(NULL, ":");
	} while (value != NULL)
	free(path);
	return (1);
}
/**
 * _build - Build the command in shell
 * @token: The execut command
 * @value: The dir of command
 * Return: dir conatining command
 */
char *_build(char *token, char *value)
{
	char *com;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	com = malloc(sizeof(char) * len);

	if (com == NULL)
		return (NULL);
	memset(com, 0, len);

	com = _strcat(com, value);
	com = _strcat(com, "/");
	com = _strcat(com, token);

	return (com);
}

/**
 * _getenv - call the PATH
 * @n: name my environment (PATH)
 * Return: NULL.
*/
char *_getenv(char *n)
{
	char *value;
	int x, y, z = 0;
	size_t n1, v1;

	n1 = _strlen(n);
	for (x = 0; env[x]; x++)
	{
		if (_strncmp(n, env[x], n1) == 0)
		{
			v1 = _strlen(env[x]) - n1;
			value =  malloc(sizeof(char) * v1);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			for (y = n1 + 1; env[i][x]; x++, z++)
			{
				value[y] = env[x][y];
			}
			value[z] = '\0';

			return (value);
		}
	}
	return (NULL);
}
