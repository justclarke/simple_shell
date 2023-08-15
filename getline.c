#include "shell.h"

/**
* _getline - read user input
* Return: input
*/
char *_getline(void)
{
	int i = 0;
	ssize_t nread;
	char c = 0, *buffer = malloc(sizeof(char) * BUF_SIZE);

	if (buffer == NULL)
	{
		return (NULL);
	}
	while (c != EOF && c != '\n')
	{
		nread = read(STDIN_FILENO, &c, 1);
		if (nread == 0 || nread == -1)
		{
			free(buffer);
			if (nread == 0)
				exit(errno);
			if (nread == -1)
				perror("Error: ");
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (i + 1 >= BUF_SIZE)
		{
			buffer = realloc(buffer, i + 1);
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
		i++;
	}
	buffer[i - 1] = '\0';
	remspace(buffer);
	comment_va(buffer);
	return (buffer);
}
/**
 * comment_va - handles comments in the shell
 * @buf: the beffer from getline
 */
void comment_va(char *buf)
{
	int i = 0;

	if (buf[0] == '#')
		buf[0] = '\0';
	else
	{
		while (buf[i] != '\0')
		{
			if (buf[i] == '#')
				buf[i] = '\0';
			i++;
		}
	}
}
