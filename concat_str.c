#include "main.h"

/**
 * concat_str - concatenates two strings with a delimiter
 * @dest: memory for concatenated string
 * @str1: first string
 * @delim: delimeter
 * @str2: second string
 * Return: void
 */
void concat_str(char *dest, char *delim, char *str1, char *str2)
{
	int i = 0, j = 0;

	if (dest == NULL)
		return;
	while (str1[i] != '\0')
	{
		dest[i] = str1[i];
		i++;
	}

	dest[i++] = delim[0];

	while (str2[j] != '\0')
	{
		dest[i + j] = str2[j];
		j++;
	}
	dest[i + j] = '\0';
}
