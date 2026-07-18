#include "main.h"

/**
 * print_line - draws a straight line
 * @n: number of underscores to print
 *
 * Return: Nothing
 */
void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	i = 0;

	while (i < n)
	{
		_putchar('_');
		i++;
	}

	_putchar('\n');
}
