#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: size of the triangle
 *
 * Return: Nothing
 */
void print_triangle(int size)
{
	int row;
	int col;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	row = 1;

	while (row <= size)
	{
		col = 1;

		while (col <= size - row)
		{
			_putchar(' ');
			col++;
		}

		col = 1;

		while (col <= row)
		{
			_putchar('#');
			col++;
		}

		_putchar('\n');
		row++;
	}
}
