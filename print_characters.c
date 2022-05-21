#include "main.h"
#include <stdlib.h>

/**
 * print_c - a function that prints out a character specifier
 * @c: refers to the string character we want to print
 *
 * Return: a numerical value of 1
 */
int print_c(va_list c)
/* where c represent the specifier for a character */
{
	char mp = (char)va_arg(c, int);

	_putchar(mp);
	return (1);
}

/**
 * print_s - rep. a function that prints out a string of character
 * @s: represent the string we want to print
 *
 * Return: the string character that was printed
 */
int print_s(va_list s)
{
	int count;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}
	return (count);
}

/**
 * hex_print - function that prints the unsigned hexadecimal value
 *             of a character in uppercase
 * @c: represents the character to print
 *
 * Return: the character printed which is 2.
 */
static int hex_print(char c)
{
	int count;
	char diff = 'A' - ':';
	char w[2];

	w[0] = c / 16;
	w[1] = c % 16;
	for (count = 0; count < 2; count++)
	{
		if (w[count] >= 10)
			_putchar('0' + diff + w[count]);
		else
			_putchar('0' + w[count]);
	}
	return (count);
}

/**
 * print_S - a function that prints a string with special
 *           character replaced by their ASCII value
 * @S: string to print
 *
 * Return: the number of characters printed
 */
int print_S(va_list S)
{
	unsigned int i;
	int count = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += hex_print(str[i]);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_r - a function that prints a string in the reverse order
 * @r: represents the string we want to print in reverse order
 *
 * Return: the number of characters printed in reverse order
 */
int print_r(va_list r)
{
	char *str;
	int i, count = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
