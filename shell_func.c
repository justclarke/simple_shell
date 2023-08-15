#include "shell.h"
/**
 * read_cmd - read the command from the terminal
 * Return: the command
 */
char *read_cmd(void)
{
	char *comm = _getline();

	return (comm);
}
/**
 * tokenize - split the command input
 * @s: string to be split
 * @arr: array of commands
 * Return: the array of commands
 */
void tokenize(char *s, char *arr[BUF_SIZE])
{
	int i = 0;
	char *token;

	token = _strtok(s, " ");
	while (token != NULL)
	{
		arr[i++] = token;
		token = _strtok(NULL, " ");
	}
	arr[i] = NULL;
}
/**
 * space - detect white space
 * @s: character
 * Return: 1 on occurence, 0 otherwise
 */
int space(char s)
{
	if (s == ' ' || s == '\t')
		return (1);
	return (0);
}
/**
 * remspace - removes space in input before tokenizing
 * @s: string to check for white space
 * Return: nothing
 */
void remspace(char *s)
{
	int i = 0, len = _strlen(s);
	int k = 0, j = len - 1;

	if (!s)
		return;
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
	while (i < len && space(s[i]))
		i++;
	while (j >= i && space(s[j]))
		j--;
	while (i <= j)
		s[k++] = s[i++];
	s[k] = '\0';
}
