#include "shell.h"
/**
 * main - shell main program
 * @av: argument vector
 * @ac: argument count
 * Return: always 0
 */
int main(UNUSED int ac, char **av)
{
	if (isatty(SRD_FILENO) == 1)
		shell_interactive(av);
	else
		shell_non_interactive(av);
	return (0);
}
/**
 * shell_interactive - runs the shell in interactive mode
 * @av: argument vector
 * Return: 0
 */
int shell_interactive(char **av)
{
	char *cmd,*args[BUF_SIZE] ;
