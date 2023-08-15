#include "shell.h"
/**
 * _getenv - the function getenv()
 * @s: string
 * Return: path
 */
char *_getenv(char *s)
{
	int i = 0, len = _strlen(s);

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], s, len) == 0 && environ[i][len] == '=')
			return (&(environ[i][len + 1]));
		i++;
	}
	return (NULL);
}
