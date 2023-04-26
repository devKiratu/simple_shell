#include "main.h"

/**
 * _getenv - gets the value of environemnt variable @key
 * @key: name of the variable
 * Return: pointer to environment variable value or NULL if it doesn't exist
 */
char *_getenv(char *key)
{
	int i = 0, j;
	char *found;

	if (key == NULL)
		return (NULL);

	while (environ[i] != NULL)
	{
		if (_strstr(environ[i], key) != NULL)
		{
			j = 0;
			while (key[j] != '\0')
			{
				if (key[j] != environ[i][j])
				{
					break;
				}
				j++;
			}
			if (environ[i][j] == '=')
			{
				found = _strchr(environ[i], '=');
				return (found++);
			}
		}
		i++;
	}
	return (NULL);
}
