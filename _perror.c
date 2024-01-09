#include "main.h"
/**
 * printed_error - a function that prints error
 * @cmd: user command input
 * @arv: prog name
 * @x: counter
 * Return: void.
 */
void pr_error(char **arv, int x, char **cmd)
{
	char *error;
	error = _toinput(x);

	PRINTED(arv[0]);
	PRINTED(": ");
	PRINTED(error);
	PRINTED(": ");
	PRINTED(cmd[0]);
	PRINTED(": illegal number: ");
	PRINTED(cmd[1]);
	PRINTED("\n");
	free(error);

}
/**
 *
 *
 *
 */
void printed_error(char *cmd, int x, char **arv)
{
	char *error;

	PRINTED(arv[0]);
	PRINTED(": ");
	er = _toinput(x);
	PRINTED(error);
	PRINTED(": ");
	PRINTED(cmd);
	PRINTED(": not found \n");
}
