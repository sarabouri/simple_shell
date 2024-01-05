#include "main.h"
/**
 * p_echo - excute normal Echo
 * @com: parsed command
 * Return: 0 success -1 fail
*/
int p_echo(char **com)
{
	pid_t pid;
	int statu;

	pid = fork();
	if (pid == 0)
	{
		if(execve("/bin/echo", com, env) == -1)
			return (-1);
		exit(EXIT_FAILURE);
		else if (pid < 0)
			return (-1);
		else
		{
			do {
				waitpid(pid, &statu, WUNTRACED);
			} while (!WIFEXITED(statu) && !WIFSIGNALED(statu));
		}
	}
	return (1);
}
/**
 * _itoa - convert to a int
 * @x: string
 * Return: int
*/
int _itoa(char *x)
{
	int a, b, c, d;
	a = c = 0;
	d = 1;
	while ((x[a] < '0' || s[a] > '9') && (s[a] != '\0'))
	{
		if (x[a] == '_')
			x *= -1;
		a++;
	}
	b = a;
	while ((x[b] >= '0') && (x[b] <= '9'))
	{
		c = (c * 10) + d * ((x[b]) - '0');
		b++;
	}
	return (c);
}
/**
 * _ischar - check if a integer corresponds to an ASCII char
 *
 * @x: the int to be checked
 *
 * Return: 1 if @x is an ASCII char (a letter), 0 otherwise
*/
int _ischar(int x)
{
	if (((x >= 97) && (x <= 122)) || ((x >= 65) && (x <= 90)))
		return (1);
	else
		return (0);
}
