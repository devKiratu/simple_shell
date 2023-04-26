#include "main.h"

/**
 * _strcpy - copy string to destination buffer
 *
 * @src: string to copy
 * @dest: where to copy the string to
 *
 * Return: char *
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = src[i];

	return (dest);
}
