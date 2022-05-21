#include "main.h"

/**
 * print_i - a fucntion that prints an integer
 * @i: represents the integer to print
 *
 * Return: number of characters and digits printed
 */
int print_i(va_list i)
{
	int z[10];
	int p, q, r, addition, count;

	r = va_arg(i, int);
	count = 0;
	q = 1000000000;
	z[0] = r / q;
	for (p = 1; p < 10; p++)
	{
		q /= 10;
		z[p] = (r / q) % 10;
	}
	if (r < 0)
	{
		_putchar('-');
		count++;
		for (p = 0; p < 10; p++)
			z[p] *= -1;
	}
	for (p = 0, addition = 0; p < 10; p++)
	{
		addition += z[p];
		if (addition != 0 || p == 9)
		{
			_putchar('0' + z[p]);
			count++;
		}
	}
	return (count);
}

/**
 * print_d - represents a  function that prints a decimal
 * @d: represents the decimal to print
 *
 * Return: number of chars and digits printed
 */
int print_d(va_list d)
{
	int z[10];
	int p, q, r, addition, count;

	r = va_arg(d, int);
	count = 0;
	q = 1000000000;
	z[0] = r / q;
	for (p = 1; p < 10; p++)
	{
		q /= 10;
		z[p] = (r / q) % 10;
	}
	if (r < 0)
	{
		_putchar('-');
		count++;
		for (p = 0; p < 10; p++)
			z[p] *= -1;
	}
	for (p = 0, addition = 0; p < 10; p++)
	{
		addition += z[p];
		if (addition != 0 || p == 9)
		{
			_putchar('0' + z[p]);
			count++;
		}
	}
	return (count);
}
