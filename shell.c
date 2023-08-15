#include "shell.h"
/**
 * main - shell main program
 * @av: argument vector
 * @ac: argument count
 * Return: always 0
 */
int main(UNUSED int ac, char **av)
{
	if (isatty(STDIN_FILENO) == 1)
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
int shell_interactive(char **av UNUSED)
{
	char *cmd UNUSED, *args[BUF_SIZE] UNUSED;
	int num;

	num = 0;
	do {
		errno = 0;
		num++;
		write(1, "sapa $>> ", 9);
		cmd = read_cmd();
	} while (1);

}
/**
 * shell_non_interactive - runs the shell in non interactiv mode
 * @av: argument vectors
 * Return: 0
 */
int shell_non_interactive(char **av UNUSED)
{
	char *cmd UNUSED, *args[BUF_SIZE] UNUSED;
	int num;

	num = 0;
	do {
		errno = 0;
		num++;
		cmd = read_cmd();
	} while (1);
}
