#include "shell.h"
/**
 * _printsd - prints a number to standard error
 * @num: the number to be printed
 */
void _printsd(int num)
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
		write(2, "0", 1);
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
