#include "main.h"

/**
 * _getline - it's a function that reads the line written in the input
 *
 *
 * Return: return input
 */

char *_getline()
{
	int j, buffersize = BUFSIZE;
	char readed, s;
	char *buffer = malloc(buffersize);

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	for (j = 0; s != EOF && s != '\n'; j++)
	{
		fflush(stdin);
		readed = read(STDIN_FILENO, &s, 1);
		if (readed == 0)
		{
			free(buffer);
			return ("\0");
		}
		buffer[j] = s;
		if (j >= buffersize)
		{
			buffer = _realloc(buffer, buffersize, buffersize + 1);
			if (buffer == NULL)
				return (NULL);
		}

	}
	buffer[j] = '\0';
	/*hundling(buffer)*/
	return (buffer);
}
/**
 * hundling - function that removes all  after the sign '#'.
 * @buff: buffer
 * Return: 0 successfully
 */
char hundling(char *buff)
{
	int x;

	for (x = 0; buff[x] != '\0'; x++)
	{
		if (buff[x] == '#')
		{
			buff[x] = '\0';
			break;

		}
	}
	return (0);
}

