#include <stdio.h>

/**
 * main - prints the alphabet in reverse
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int c;

	c = 'z';
	while (c >= 'a')
	{
		putchar(c);
		c--;
	}

	putchar('\n');

	return (0);
}
