#include "main.h"

/**
 * _setenv - Initialize new environment variable or modify an existing one
 * @argv: commands array
 * @name: name of the executing program
 * Return: 0 on success, -1 on error
 */
int _setenv(char *argv[], char *name)
{
	char *new_var, *key, *val;

	if (argv[1] == NULL || argv[2] == NULL)
	{
		fprintf(stderr, "%s: Usage - setenv VARIABLE VALUE\n", name);
		return (-1);
	}
	key = argv[1];
	val = argv[2];

	new_var = malloc(strlen(key) + strlen(val) + 2);
	if (new_var == NULL)
	{
		fprintf(stderr, "%s: Could not initialize new variable", name);
		return (-1);
	}
	sprintf(new_var, "%s=%s", key, val);
	return (handle_env_update(key, new_var, name));
}

/**
 * handle_env_update - overwrites env if key is found, adds new variable if not
 * @key: environment variable key
 * @new_var: formatted environment variable to be used
 * @name: name of the executing program
 * Return: 0 on success, -1 on failure
 */
int handle_env_update(char *key, char *new_var, char *name)
{
	int i = 0, j = 0;
	char **new_env;

	/* overwrite variable if exists */
	while (environ[i] != NULL)
	{
		if (strstr(environ[i], key) != NULL)
		{
			environ[i] = new_var;
			return (0);
		}
		i++;
	}

	/* key does not exist, create new variable */
	new_env = malloc(sizeof(char *) * (i + 2));
	if (new_env == NULL)
	{
		fprintf(stderr, "%s: Could not update env list", name);
		return (-1);
	}

	while (j < i)
	{
		new_env[j] = environ[j];
		j++;
	}
	new_env[j] = new_var;
	new_env[++j] = NULL;
	environ = new_env;
	return (0);
}
