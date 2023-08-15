#include "shell.h"
/**
 * print_list - prints the list
 * @head: head of list
 */
void print_list(struct node *head)
{
	while (head != NULL)
	{
		write(STDOUT_FILENO, head->s, _strlen(head->s));
		write(STDOUT_FILENO, "\n", 1);
		head = head->next;
	}
}
/**
 * free_list - free up malloc
 * @head: head of list
 */
void free_list(struct node *head)
{
	struct node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
/**
 * _env - env function
 * Return: 0
 */
int _env(void)
{
	char **env;
	struct node *head = NULL;

	for (env = environ; *env != NULL; env++)
		add_node(&head, new_node(*env));
	print_list(head);
	free_list(head);
	return (0);
}
/**
 * _unsetenv - unsetenv
 * @name: name of environment variable
 * Return: 0
 */
int _unsetenv(char *name)
{
	char **e;
	char **env;
	size_t len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			for (e = env; *e != NULL; e++)
				*e = *(e + 1);
			return (0);
		}
	}

	return (-1);
}
/**
 * _setenv - setenv
 * @name: name of the variable to set
 * @value: value
 * Return: 0
 */
int _setenv(char *name, char *value)
{
	char **env;
	struct node *head = NULL;

	for (env = environ; *env != NULL; env++)
		add_node(&head, new_node(*env));

	add_env_var(&head, name, value);
	update_environ(head);
	free_list(head);
	return (0);
}

