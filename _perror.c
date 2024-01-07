#include "main.h"
/**
 * printed_error - a function that prints error
 * @cmd: user command input
 * @arv: prog name
 * @count: counter
 * Return: void.
 */
void printed_error(char *cmd, int x, char **arv)
{
	char *error = _toinput(x);

	PRINTED(arv[0]);
	PRINTED(": ");
	error = _toinput(x);
	PRINTED(error);
	free(error);
	PRINTED(": ");
	PRINTED(cmd);
	PRINTED(": notfound\n");

}
