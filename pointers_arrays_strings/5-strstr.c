#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring to find
 *
 * Return: pointer to beginning of substring or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	char *start;
	char *check;

	if (*needle == '\0')
		return (haystack);

	while (*haystack != '\0')
	{
		start = haystack;
		check = needle;

		while (*start == *check && *check != '\0')
		{
			start++;
			check++;
		}

		if (*check == '\0')
			return (haystack);

		haystack++;
	}

	return (NULL);
}
