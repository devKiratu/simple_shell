#include "main.h"

/**
 * create_argv - splits a string into an aray of tokens
 * @s: string to split
 *
 * Return: string array, or NULL if failure
 */
char **create_argv(char *s)
{
	char *token, **arr, *delim = " \n";
	int len = 0, i = 0, j = 0;

	/* Get length of s */
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			len++;
		i++;
	}

	/* Allocate memory for arr */
	arr = malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		return (NULL);

	token = strtok(s, delim);

	while (token != NULL)
	{
		/* copy token to array */
		arr[j] = malloc(sizeof(char) * (strlen(token) + 1));
		if (arr[j] == NULL)
		{
			while (j > 0)
				free(arr[--j]);
			free(arr);
			break;
		}

		/* copy token to array */
		strcpy(arr[j], token);

		j++;

		/* get next token */
		token = strtok(NULL, delim);
	}
	arr[j] = NULL;
	return (arr);
}
