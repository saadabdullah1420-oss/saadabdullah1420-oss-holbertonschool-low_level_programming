#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - prints a char
 * @args: arguments list
 *
 * Return: Nothing
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an integer
 * @args: arguments list
 *
 * Return: Nothing
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: arguments list
 *
 * Return: Nothing
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: arguments list
 *
 * Return: Nothing
 */
void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		printf("(nil)");
	if (str != NULL)
		printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	unsigned int j;
	char *separator = "";
	char types[] = {'c', 'i', 'f', 's'};
	void (*functions[])(va_list) = {
		print_char,
		print_int,
		print_float,
		print_string
	};

	va_start(args, format);

	while (format != NULL && format[i])
	{
		j = 0;

		while (j < 4)
		{
			if (format[i] == types[j])
			{
				printf("%s", separator);
				functions[j](args);
				separator = ", ";
			}
			j++;
		}

		i++;
	}

	printf("\n");

	va_end(args);
}
