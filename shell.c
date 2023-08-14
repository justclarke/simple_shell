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
