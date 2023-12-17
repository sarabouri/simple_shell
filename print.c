#include  "main.h"

/**
 * print - function that prints input c
 * @c: character to be printed
 * Return: returns written characters
 */
size_t print(char *c)
{
    return (write (STDOUT_FILENO, c, strlen(c))); //create your STRLEN//
}
