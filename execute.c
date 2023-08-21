#include "shell.h"
/**
 * handle_path - handles the path and executes the command
 * @arr: the array containing the commands
 * @av: argument vector
 * @count: command count
 * Return: ex_code
 */
void handle_path(char **arr, char **av, int count)
{
	char *f_str, *f_path;

	if (arr == NULL)
		return;
	f_str = arr[0];
	errno = 0;
	if (arr[0][0] == '/')
	{
		if (access(f_str, X_OK) == 0)
			execute(arr);
		else
		{
			_perror(f_str, av, count);
			return;
		}
	}
	else if (arr[0][0] == '.')
	{
		f_path = arr[0];
		if (access(f_path, X_OK) == 0)
			execute(arr);
		else
		{
			_perror(f_str, av, count);
			return;
		}
	}
	else
	{
		f_path = make_path(arr[0]);
		arr[0] = f_path;
		if (access(f_path, X_OK) == 0)
			execute(arr);
		else
		{
			_perror(f_str, av, count);
			return;
		}
		free(f_path);
	}
}
/**
 * execute - executes the give commands
 * @arr: the array of commands
 * Return: status
 */
void execute(char **arr)
{
	int status;
	pid_t father;

	father = fork();
	if (father == -1)
	{
		exit(1);
	}
	if (father == 0)
	{
		if ((execve(arr[0], arr, environ) == -1))
		{
			errno = 127;
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
		errno = WEXITSTATUS(status);
}
/**
 * make_path - make the full path and checks with access
 * @p: command
 * Return: the full path
 */
char *make_path(char *p)
{
	char *dir, *path, *full;

	path = _strdup(_getenv("PATH"));
	dir = _strtok(path, ":");
	while (dir != NULL)
	{
		full = malloc(_strlen(dir) + _strlen(p) + 2);
		_strcpy(full, dir);
		_strcat(full, "/");
		_strcat(full, p);
		if (access(full, X_OK) == 0)
		{
			free(path);
			return (full);
		}
		free(full);
		dir = _strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
