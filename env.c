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
 * check_builtin - check builtin
 *
 * @com: command to check
 * Return: 0 success -1 fail
*/
int check_builtin(char **com)
{
	bul fun[] = {
		{"cd", NULL},
		{"echo", NULL},
		{NULL, NULL}
	};
	int x = 0;

	if (*com == NULL)
		return (-1);
	while ((fun + x)->comm)
	{
		if (_strcmp(com[0], (fun + x)->comm) == 0)
			return (0);
		x++;
	}
	return (-1);
}
/**
 * handle_built - Handle builtin command
 * @com: parsed command
 * @er: statue of last excute
 * Return: -1 fail 0 succes (Return: Exute Builtin)
*/
int handle_built(char **com, int er)
{
	bul bil[] = {
		{"cd", _cdir},
		{"env", pr_env},
		{"echo", echo},
		{NULL, NULL}
	};
	int x = 0;

	while ((bil + x)->comm)
	{
		if (_strcmp(com[0], (bil + x)->comm) == 0)
			return ((bil + x)->fun(com, er));
		x++;
	}
	return (-1);
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
			z = 0;
			for (y = n1 + 1; env[1][x]; x++, z++)
			{
				value[y] = env[x][y];
			}
			value[z] = '\0';

			return (value);
		}
	}
	return (NULL);
}
