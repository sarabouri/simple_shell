#include "main.h"
/**
 * printed_error - a function that prints error
 * @cmd: user command input
 * @arv: prog name
 * Return: void.
 */
void printed_error(char *cmd, int count, char **arv)
{
	char *error;

	PRINTED(argv[0]);
	PRINTED(": ");
	er = _itoa(count); /* need to e veried*/
	PRINTED(error);
	free(error);
	PRINTED(": ");
	PRINTED(cmd);
	PRINTED(": notfound\n");

}
