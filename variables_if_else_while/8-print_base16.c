#include <stdio.h>

/**
 * main - prints hexadecimal numbers in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			putchar(i + '0');
		else
			putchar(i - 10 + 'a');
		i++;
	}

	putchar('\n');

	return (0);
}
