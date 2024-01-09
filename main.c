#include "main.h"

/**
 * pprompt - this function is used to display the prompt
 *
 */

void pprompt(void)
{

	PRINTED("$ ");
}

/**
 * user_input - this function allows user to enter command
 * @command: user's entered command
 * @array: command size
 * Return: void.
 */

void user_input(char *command, size_t array)
{
	if (fgets(command, array, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_putchar('\n'); /**putchar required**/
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
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

/**
 * main - Entry point
 * @arv: standard input (stdin)
 * @argc: number of arguments
 * Return: 0 on success
 */

int main(int argc, char *arv[])
{
	char *line, **command;
	int x = 0, status = 1, str = 0;
	(void)argc;

	if (arv[1] != NULL)
		read_f(arv[1], arv);
	signal(SIGINT, signal_handel); /*need to be verifies*/
	while (status)
	{
		x++;
		if (isatty(STDIN_FILENO))
			pprompt();
		line = _getline();
		if (line[0] == '\0')
		{
			continue;
		}
		command = parse_input(line);
		if (_strcmp(command[0], "exit") == 0)
		{
			_exit_d(command, line, arv, x);
		}
		else if (check_builtin(command) == 0)
		{
			str = handle_built((char **)command, str);
			continue;
		}
		else
		{
			str = check_com(command, line, x, arv);
		}
		free_koulshi(command, line);
	}
	return (status);
}
