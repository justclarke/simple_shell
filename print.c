#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}
/**
 * _printf - prints a string
 * @s: string
 */
void _printf(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}
/**
 * _print_d - prints numbers
 * @num: the number to be printed
 */
void _print_d(int num)
{
	int len = 0;
	char buffer[BUF_SIZE], temp;
	int is_negative = num < 0 ? 1 : 0;
	int copy, digit_count, digit, i;

	if (is_negative)
	{
		buffer[len++] = '-';
		num = -num;
	}

	copy = num;
	digit_count = 0;

	do {
		digit_count++;
		copy /= 10;
	} while (copy);
	if (num == 0)
	{
		write(1, "0", 1);
	}

	for (i = 0; i < digit_count; i++)
	{
		digit = num % 10;
		num /= 10;
		buffer[len++] = digit + '0';
	}
	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}
	write(2, buffer, len);
}
/**
 * _perror - print error message
 * @arr: array of commands
 * @arg: name of the command
 * @count: count of command
 */
void _perror(char *arg, char **arr, int count)
{
	errno = 127;
	_printf(arr[0]);
	_printf(": ");
	_print_d(count);
	_printf(": ");
	_printf(arg);
	_printf(": ");
	_printf("not found\n");
}
/**
 * _pstderr - prints to stderr
 * @arr: array of commands
 * @av: argument vector
 * @count: count
 * @fc: wrong argument
 */
void _pstderr(char **arr, char **av, int count, char *fc)
{
	write(2, av[0], _strlen(av[0]));
	write(2, ": ", 2);
	_print_d(count);
	write(2, ": ", 2);
	write(2, arr[0], _strlen(arr[0]));
	write(2, ": ", 2);
	write(2, "Illegal number", 14);
	write(2, ": ", 2);
	write(2, fc, _strlen(fc));
	write(2, "\n", 1);
}
