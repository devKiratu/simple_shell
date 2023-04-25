#include "main.h"

/**
 * _unsetenv - removes an environment variable
 * @argv: commands array containing the variable to remove
 * @name: name of the executing program
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char *argv[], char *name)
{
	int i = 0, j = 0, k = 0;
	char **new_env, *key;

	if (argv[1] == NULL)
	{
		fprintf(stderr, "%s: Usage - unsetenv VARIABLE\n", name);
		return (-1);
	}
	key = argv[1];

	if (getenv(key) == NULL)
	{
		fprintf(stderr, "%s: %s doesn't exist\n", name, key);
		return (0);
	}

	while (environ[i] != NULL)
		i++;
	new_env = malloc(sizeof(char *) * i);
	if (new_env == NULL)
	{
		fprintf(stderr, "%s: Can't update env list", name);
		return (-1);
	}
	while (k < i)
	{
		if (strstr(environ[k], key) != NULL)
		{
			k++;
			continue;
		}
		new_env[j] = environ[k];
		j++;
		k++;
	}
	new_env[j] = NULL;
	environ = new_env;
	return (0);
}
