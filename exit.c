#include "main.h"
/**
 * _exit_d - exit statue shell
 * @com: parsed command
 * @buff: user input
 * @av: program name
 * @i: excute count
 * Return: void
*/
void _exit_d(char **com, char *buff, char **av, int i)
{
	int str, x = 0;

	if (com[1] == NULL)
	{
		free(buff);
		free(com);
		exit(EXIT_SUCCESS);
	}
	for (x = 0; com[1][x]; x++)
	{
		if (_ischar(com[1][x++]) != 0)
		{
			pr_error(av, i, com);
			break;
		}
		else
		{
			str = _itoa(com[1]);
			free(buff);
			free(com);
			exit(str);
		}
	}
}

/**
 * _cdir - change dirctorie
 * @com: parsed command
 * @x: statue last command exuted
 * Return: 0success 1 failed
*/
int _cdir(char **com, __attribute__((unused))int x)
{
	int v1 = -1;
	char str[1000];

	if (com[1] == NULL)
	{
		v1 = chdir(_getenv("HOME"));
	}
	else if (_strcmp(com[1], "_") == 0)
	{
		v1 = chdir(_getenv("OLDPWD"));
	}
	else
		v1 = chdir(com[1]);
	if (v1 == -1)
	{
		perror("ERROR");
		return (-1);
	}

	else if (v1 != -1)
	{
		getcwd(str, sizeof(str));
		setenv("OLDPWD", (const char *)_getenv("PWD"), 1);
		setenv("PWD", (const char *)com, 1);
	}
	return (0);
}

/**
 * pr_env - display enviroment variable
 * @com: parsed command
 * @x: statue of last command excuted
 * Return: always 0
*/
int pr_env(__attribute__((unused))char **com, __attribute__((unused))int x)
{
	size_t i;
	int y;

	for (i = 0; env[i] != NULL; i++)
	{
		y = _strlen(env[i]);
		write(1, env[i], y);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * echo - Excute echo cases
 * @x: statue of last command excuted
 * @com: parsed command
 * Return: always 0 or excute normal echo
*/
int echo(char **com, int x)
{
	char *p;
	unsigned int pid = getppid();

	if (_strncmp(com[1], "$?", 2) == 0)
	{
		ptint_n(x);
		PRINTED("\n");
	}
	else if (_strncmp(com[1], "$$", 2) == 0)
	{
		print_n(pid);
		PRINTED("\n");
	}
	else if (_strncmp(com[1], "$PATH", 5) == 0)
	{
		p = _getenv("PATH");
		PRINTED(p);
		PRINTED("\n");
		free(p);
	}
	else
		return (printd_echo(com));
	return (1);
}
/**
 * _intl - determine legth of int
 * @n: giveen int
 * Return: length of int
*/
int _intl(int n)
{
	int l;

	for (l = 0; n != 0; l++)
	{
		n /= 10;
	}
	return (l);
}
