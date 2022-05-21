#include "main.h"

/**
 * print_hex - a function that printsout unsigned int in hexadicmal
 * @g: unsigned int to print
 * @h: represents the flag decides what to print. where 0 rep lower
 *     case and 1 rep upper case
 *
 * Return: num of printed digit
 */
int print_hex(unsigned int g, unsigned int h)
{
	unsigned int n[8];
	unsigned int j, k, add;
	char diff;
	int count;

	k = 268435456; /* (16 ^ 7) */
	if (h)
		diff = 'A' - ':';
	else
		diff = 'a' - ':';
	n[0] = g / k;
	for (j = 1; j < 8; j++)
	{
		k /= 16;
		n[j] = (g / k) % 16;
	}
	for (j = 0, add = 0, count = 0; j < 8; j++)
	{
		add += n[j];
		if (add || j == 7)
		{
			if (n[j] < 10)
				_putchar('0' + n[j]);
			else
				_putchar('0' + diff + n[j]);
			count++;
		}
	}
	return (count);
}
/**
 * print_x - function that takes an unsigned int and prints it
 *           in lower case hexadecimal form where
 * @x: represents the unsigned integer
 *
 * Return: no. of the printed digit
 */
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}

/**
 * print_X - a function that prints an unsigned int in uppercase
 *           and hexadecimal form
 * @X: represent the unsigned int
 *
 * Return: unsigned int in hexadecimal form
 */
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}

/**
 * _pow - a function that calculates an exponential value
 * @base: represents the base of exponent value
 * @exp: represents exponent of number
 *
 * Return: base ^ exp
 */
static unsigned long _pow(unsigned int base, unsigned int exp)
{
	unsigned int i;
	unsigned long answer = base;

	for (i = 1; i < exp; i++)
	{
		answer *= base;
	}
	return (answer);
}

/**
 * print_p - function that prints an address to a pointer
 * @p: represent the address to print
 *
 * Return: no. of characters to print
 */
int print_p(va_list p)
{
	int count = 0;
	unsigned int a[16];
	unsigned int i, sum;
	unsigned long n, m;
	char *str = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	m = _pow(16, 15); /* 16 ^ 15 */
	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			count++;
		}
	}
	return (count);
}
