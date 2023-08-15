#include "shell.h"
/**
 * _strtok - custom strtok function
 * @str: the string to be checked
 * @delim: delimiters
 * Return: array of strings
 */
char *_strtok(char *str, char *delim)
{
	static char *save_ptr;
	char *end;

	if (str != NULL)
		save_ptr = str;

	if (save_ptr == NULL || *save_ptr == '\0')
		return (NULL);

	end = save_ptr;
	while (*save_ptr != '\0' && _strchr(delim, *save_ptr) == NULL)
		save_ptr++;

	if (*save_ptr != '\0')
	{
		*save_ptr = '\0';
		save_ptr++;
	}

	return (end);
}
