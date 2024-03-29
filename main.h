#ifndef MAIN_H
#define MAIN_H

extern char **environ;

/*libary*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <syscall.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
/*our defines*/
#define BUFSIZE 1024
#define MAX_TOKEN 150
#define PRINTED(c) (write(STDOUT_FILENO, c, _strlen(c)))
/* our_fun */
/*main.c*/
void pprompt(void);
void user_input(char *command, size_t array);
char execution(const char *cmd);
/*putchar.c*/
int _putchar(char c);
void print_n(unsigned int m);
void ptint_n(int m);
/*getline.c*/
char *_getline(void);
char hundling(char *buff);
/*_memo1*/
void *_realloc(void *p, unsigned int o_size, unsigned int n_size);
char *_memcpy(char *d, char *s, unsigned int F);
void *_fill_an_array(void *a, int element, size_t L);
void free_koulshi(char **command, char *ligne);
void free_enviro(char **enviro);
/*preorr*/
void pr_error(char **arv, int x, char **cmd);
void printed_error(char *cmd, int x, char **arv);
/*env.c*/
int com_path(char **com);
char *_build(char *token, char *value);
int check_builtin(char **com);
int handle_built(char **com, int er);
char *_getenv(char *n);
/*string1.c*/
char *_strcat(char *d, char *s);
char *_strdup(char *s);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strcpy(char *d, char *s);
/*string2.c*/
char *_strchr(char *s, char a);
int _strncmp(const char *str1, const char *str2, size_t l);
/*strtok.c*/
char *_strtok(char *s, const char *delimiter);
unsigned int delim_check(char a, const char *s);
char **parse_input(char *cmd);
/*_memo2.c*/
int printd_echo(char **com);
int _itoa(char *x);
int _ischar(int x);
char *_toinput(unsigned int x);
void array_rv(char *ar, int l);
/*exit.c*/
void _exit_d(char **com, char *buff, char **av, int i);
int _cdir(char **com, __attribute__((unused))int x);
int pr_env(char **com, int x);
int echo(char **com, int x);
int _intl(int n);
/*exect1.c*/
void read_f(char *fname, char **argv);
void ftreat(char *line, int coun, FILE *pf, char **argv);
void exit_f(char **com, char *buff, FILE *pf);
int check_com(char **com, char *intp, int x, char **argv);
void signal_handel(int s);

/**
 * struct bulltin - this struct contains bultin to handle and func
 * @comm: Pointer
 * @fun: when bultin is true fun is executed
*/
typedef struct bulltin
{
	int (*fun)(char **line, int er);
	char *comm;
} bul_t;
#endif /* main.h */
