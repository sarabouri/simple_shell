#include "main.h"

/**
 * _putchar -  writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success1.
 * On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_n - this function prints a number
 * @m: this is an unsigned integer
 * Return: void.
 */
void print_n(unsigned int m)
{
	unsigned int i = m;

	if ((i / 10) > 0)
		print_n(i / 10);

	_putchar(i % 10 + '0');
}
/**
 * ptint_n - this function prints nuber using putchar
 * @m: this is an integer
 * Return: void.
 */
void ptint_n(int m)
{
	unsigned int c = m;

	if (m < 0)
	{
		_putchar('-');
		c = -c;
	}
	if ((c / 10) > 0)
			print_n(c / 10);

	_putchar(c % 10 + '0');
}
