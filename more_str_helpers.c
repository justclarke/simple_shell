#include "shell.h"
/**
* _strdup - function that returns a pointer to a newly allocated
* space in memory, which contains a copy of the string given as a parameter
* @str: string to be duplicated
* Return: pointer to duplicated string, on success. null for
* insufficient memory
*/
char *_strdup(char *str)
{
	char *c;
	int i = 0, j;

	if (str == NULL)
	{
		return (NULL);
		exit(1);
	}
	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}
	c = (char *)malloc(sizeof(char) * (j + 1));
	if (c == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		c[i]  = str[i];
	}
	return (c);
}
/**
* _strchr - locates a character in a string
* @s: string to search
* @c: character to be found
* Return: a pointer to the first occurence
*/
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}
