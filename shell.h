#ifndef SHELL_H
#define SHELL_H

/**MACROS**/
#define UNUSED __attribute__((unused))
#define BUF_SIZE 1024

/**LIBRARIES**/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdlib.h>

/**SHELL_FUNCTIONS**/
int shell_interactive(char **av);
int shell_non_interactive(char **av);
char *read_cmd(void);
void tokenize(char *s, char *arr[BUF_SIZE]);
int space(char s);
void remspace(char *s);
int check_builtins(char **arr);
void comment_va(char *buf);
int handle_path(char **arr, char **av, int count);
int execute(char **arr);
char *makae_path(char *p);
void _perror(char **arr, int count);

/**
 * struct node - linked list
 * @s: string
 * @next: pointer to next node
 */
struct node
{
	char *s;
	struct node *next;
};
static struct node *new_node(char *s) UNUSED;
/**
 * new_node - creates new node
 * @s: string
 * Return: pointer to new node
 */
static struct node *new_node(char *s)
{
	struct node *n = malloc(sizeof(struct node));

	if (n == NULL)
		return (NULL);

	n->s = s;
	n->next = NULL;
	return (n);
}
static void add_node(struct node **head, struct node *n) UNUSED;
/**
 * add_node - adds node to end of list
 * @head: pointer to the head of list
 * @n: node to be added to end of list
 */
static void add_node(struct node **head, struct node *n)
{
	if (*head == NULL)
		*head = n;
	else
	{
		struct node *current = *head;

		while (current->next != NULL)
			current = current->next;
		current->next = n;
	}
}
/** CUSTOM FUNCTIONS **/
char *_strtok(char *str, char *delim);
char *_getline(void);
char *_getenv(char *s);

/** STR HELPERS **/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_memcpy(char *dest, char *src, size_t n);
void add_env_var(struct node **head, char *name, char *value);
void update_environ(struct node *head);

/** PRINT HELPERS **/
void _printf(char *s);
void _print_d(int num);
int _putchar(char c);
void print_list(struct node *head);
void free_list(struct node *head);

/** COMMANDS **/
void exit_func(int status);
extern char **environ;
int _env(void);
int _unsetenv(char *name);
int _setenv(char *name, char *value);
void cd_func(const char *dir);

/** UTILITIES **/
int _atoi(char *s);
#endif
