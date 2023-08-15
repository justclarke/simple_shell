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
	return (write(1, &c, 1));
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
	write(1, buffer, len);
}
/**
 * _perror - print error message
 * @arr: array of commands
 * @count: count of command
 */
void _perror(char **arr, int count)
{
	errno = 127;
	_printf(arr[0]);
	_printf(": ");
	_print_d(count);
	_printf(": ");
	_printf("command not found \n");
}
