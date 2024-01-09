#include "main.h"
/**
 * printed_error - a function that prints error
 * @cmd: user command input
 * @arv: prog name
 * @x: counter
 * Return: void.
 */
void printed_error(char **arv, int x, char **cmd)
{
	char *error;
       /*	= _toinput(x);*/

	PRINTED(arv[0]);
	PRINTED(": ");
	error = _toinput(x);
	PRINTED(error);
	free(error);
	PRINTED(": ");
	PRINTED(cmd);
	PRINTED(": notfound\n");

}
