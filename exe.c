#include "main.h"

/**
 * execution - this function is used to execute command files from the root
 * @cmd: command
 * Return: 0.
 */

char execution(const char *cmd)
{
	pid_t process = fork();
	if (process < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (process == 0)
	{
		execlp(cmd, cmd, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
