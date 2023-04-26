#include "main.h"

/**
 * _strlen - determine the length of a string
 *
 * @s: string to test
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int length = 0, i = 0;

	while (s[i] != '\0')
	{
		length++;
		i++;
	}

	return (length);
}
