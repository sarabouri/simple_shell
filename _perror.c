#include "main.h"
/**
 * pr_error - a function that prints error
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
 * printed_error - this function
 * @cmd:input command
 * @x:integer
 * @arv: argument
 *ٌ Return: void
 */
void printed_error(char *cmd, int x, char **arv)
{
	char *error;

	PRINTED(arv[0]);
	PRINTED(": ");
	error = _toinput(x);
	PRINTED(error);
	PRINTED(": ");
	PRINTED(cmd);
	PRINTED(": not found \n");
}
