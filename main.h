#ifndef MAIN_H
#define MAIN_H

extern char **env;

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

/* our_fun */
/*main.c*/
char pprompt(char *x);
void user_input(char *command, size_t array);
char execution(const char *cmd);
/*putchar.c*/
int _putchar(char c);
/*getline.c*/
char *_getline();
char hundling(char *buff);

typedef struct bulltin
{
	char *comm;
	int (*fun)(char **line, int er);
} bul
#endif /* main.h */
