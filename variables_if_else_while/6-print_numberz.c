#include <stdio.h>

/**
 * main - prints numbers from 0 to 9
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	i = 0;
	while (i <= 9)
	{
		putchar(i + '0');
		i++;
	}

	putchar('\n');

	return (0);
}
