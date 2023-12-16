#include  "main.h"

/**
 * print - function that prints input c
 * @c: character to be printed
 * Return: returns written characters
 */
char print(char *c)
{
    return (write(STDOUT_FILENO, c, sizeof(c) - 1));
}
