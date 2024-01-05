#include "main.h"
/**
 * read_f - Read command from file
 * @fname: file name
 * @argv: program name
 * Return: -1 or 0
*/
void read_f(char *fname, char **argv)
{
	FILE *pf;
	char *line = NULL;
	size_t len =0 ;
	int coun = 0;

	pf = fopen(fname, "r");
	if (pf == NULL)
		exit(EXIT_FAILURE);
	while ((_getline(&line, &len,pf)) != -1)
	{
		coun++;
		ftreat(line, counter, pf, argv);
	}
	if (line)
		free(line);
	fclose(pf);
	exit(0);
}
/**
 * ftreat - PARSE check command fork wait excut in line of file
 * @line: line from a file
 * @coun: error counter
 * @pf: file descriptor
 * @argv: program name
 * Return: excute a line void
*/
void ftreat(char *line, int coun, FILE *pf, char ** argv)
{
	char **com;
	int str = 0;

	com = pars_com(line);

	if (_strncmp(com[0], "exit", 4) == 0)
		exit_f(com, line, pf);
	else if (check_builtin(com) == 0)
	{
		str = handle_built(com, str);
		free(com);
	}
	else
	{
		str = check_com(com, line, coun, argv);
		free(com);
	}
}
/**
 * exit_f - exit shell case of file
 * @buff: line from a file
 * @com: parse command
 * @pf: file descriptor
 * Return: case of exit in a file line
*/
void exit_f(char **com, char *buff, FILE *pf)
{
	int statu;
	int i = 0;

	if (com[1][i] = NULL)
	{
		free(buff);
		free(com);
		fclose(pf);
		exit(errno);
	}
	while (com[1][i])
	{
		if (_ischar(com[1][i++]) < 0)
			perror("illegal number");
	}
	statu = _itoa(com[1]);
	free(buff);
	free(com);
	fclose(pf);
	exit(statu);
}
