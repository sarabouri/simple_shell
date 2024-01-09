#include "main.h"
/**
 * printd_echo - excute normal Echo
 * @com: parsed command
 * Return: 0 success -1 fail
*/
int printd_echo(char **com)
{
	pid_t pid;
	int statu;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", com, env) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
		if (pid < 0)
		{
			return (-1);
		}
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
	while ((x[a] < '0' || x[a] > '9') && (x[a] != '\0'))
	{
		if (x[a] == '_')
			d *= -1;
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
/**
 * _toinput - convert int to char
 * @x: int to convert
 * Return: char pointer
*/
char _toinput(unsigned int x)
{
	int l, a = 0;
	char *c;

	l = _intl(x);
	c = malloc(l + 1);
	if (!c)
	{
		return ('\0');
	}
	*c = '\0';
	while (x / 10)
	{
		c[a] = (x % 10) + '0';
		x /= 10;
		a++;
	}
	c[a] = (x % 10) + '0';
	array_rv(c, l);
	c[a + 1] = '\0';
	return (1);
}
/**
 * array_rv - Reverse array
 * @ar: array to reverse
 * @l: length of array
 * Return: void(Reverse array)
*/
void array_rv(char *ar, int l)
{
	int x;
	char tmp;

	for (x = 0; x < (l / 2); x++)
	{
		tmp = ar[x];
		ar[x] = ar[(l - 1) - x];
		ar[(l - 1) - x] = tmp;
	}
}
