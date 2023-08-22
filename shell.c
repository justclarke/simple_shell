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
int shell_interactive(UNUSED char **av)
{
	char *cmd UNUSED, *args[BUF_SIZE] UNUSED;
	int num, exit_s;

	errno = 0;
	num = 0;
	signal(SIGINT, ctrlc);
	do {
		num++;
		write(1, "sapa $>> ", 9);
		cmd = read_cmd();
		if (cmd == NULL)
			exit(errno);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
			continue;
		remspace(cmd);
		tokenize(cmd, args);
		if (check_builtins(args) == 0)
		{
		}
		else if (_strcmp(args[0], "exit") == 0)
		{
			exit_s = exit_func(args, av, num, args[1]);
			free(cmd);
			if (exit_s == 123)
				exit(errno);
			else
				exit(exit_s);
		}
		else
			handle_path(args, av, num);
		free(cmd);
	} while (1);
	return (0);
}
/**
 * shell_non_interactive - runs the shell in non interactiv mode
 * @av: argument vectors
 * Return: 0
 */
int shell_non_interactive(UNUSED char **av)
{
	char *cmd UNUSED, *args[BUF_SIZE] UNUSED;
	int num, exit_s;

	errno = 0;
	num = 0;
	do {
		num++;
		cmd = read_cmd();
		if (cmd == NULL)
			exit(errno);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
			continue;
		remspace(cmd);
		tokenize(cmd, args);
		if (check_builtins(args) == 0)
		{
		}
		else if (_strcmp(args[0], "exit") == 0)
		{
			exit_s = exit_func(args, av, num, args[1]);
			free(cmd);
			if (exit_s == 123)
				continue;
			exit(exit_s);
		}
		else
			handle_path(args, av, num);
		free(cmd);
	} while (1);
}
/**
 * ctrlc - signal handle for ctrlc
 * @sig: signal number
 */
void ctrlc(int sig __attribute__((unused)))
{
	write(1, "\n", 1);
	exit(0);
}
