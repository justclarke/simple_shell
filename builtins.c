#include "shell.h"
/**
 * check_builtins - checks the builtin functions against cmd
 * @arr: array of commands
 * Return: 0 on success, 1 on failure
 */
int check_builtins(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		i++;

	if (_strcmp(arr[0], "env") == 0)
	{
		_env();
		return (0);
	}
	else if (strcmp(arr[0], "cd") == 0)
	{
		cd_func(arr[1]);
		return (0);
	}
	else if (_strcmp(arr[0], "unsetenv") == 0)
	{
		if (i == 2)
		{
			_unsetenv(arr[1]);
			return (0);
		}
	}
	else if (_strcmp(arr[0], "setenv") == 0)
	{
		if (i == 3)
		{
			_setenv(arr[1], arr[2]);
			return (0);
		}
	}
	return (-1);
}
/**
 * exit_func - function for exit
 * @status: exist statues
 */
int exit_func(char **arr, char **av, int count, char *status UNUSED)
{
	int code = errno, i;

	if (status != NULL)
	{
		i = 0;
		while (status[i])
		{
			if (!(status[i] > 47 && status[i] < 58))
			{
				_pstderr(arr, av, count, status);
				errno = 2;
				return (123);
			}
			i++;
		}
		code = _atoi(status);
	}
	return (code);
}

/**
 * env_func - function for environ cmd
 */
void env_func(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
/**
 * cd_func - change the current directory of the the process
 * @dir: Directory to change to NULL
 */
void cd_func(const char *dir)
{
	char *current_dir;
	int ret;

	if (dir == NULL)
	{
		dir = _getenv("HOME");
	}

	current_dir = getcwd(NULL, 0);
	if (current_dir == NULL)
	{
		perror("getcwd");
		return;
	}

	ret = chdir(dir);
	if (ret == -1)
	{
		perror("cd");
	}
	else
	{
		ret = setenv("PWD", dir, 1);
		if (ret == -1)
		{
			perror("setenv");
		}
	}

	free(current_dir);
}
