#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to the string
 */
char *cap_string(char *str)
{
	int i;
	int cap;

	i = 0;
	cap = 1;

	while (str[i] != '\0')
	{
		if (cap && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;

		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == ',' || str[i] == ';' || str[i] == '.' ||
			str[i] == '!' || str[i] == '?' || str[i] == '"' ||
			str[i] == '(' || str[i] == ')' || str[i] == '{' ||
			str[i] == '}')
			cap = 1;
		else
			cap = 0;

		i++;
	}

	return (str);
}
