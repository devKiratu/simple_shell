#include "main.h"

/**
 * _strchr - locates a character in the string
 *
 * @s: string
 * @c: character to locate
 *
 * Return: pointer to first occurrence of @c
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] >= '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}

	return (0);
}
