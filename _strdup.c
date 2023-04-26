#include "main.h"

/**
 * _strdup - duplicates a string @str
 * @str: string to duplicate
 * Return: pointer to duplicated string or NULL if it fails
 */
char *_strdup(char *str)
{
	char *new_str;

	new_str = malloc(sizeof(char) * (_strlen(str) + 1));
	if (new_str == NULL)
		return (NULL);
	_strcpy(new_str, str);

	return (new_str);
}
