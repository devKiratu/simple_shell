#include "main.h"

/**
 * create_full_path - takes a command, and constructs its full if it exists
 * @cmd: command to create full path from
 * @argv: address of the commandline arguments to execute together with
 * Return: full path created or NULL in case of failure
 */
char *create_full_path(char *cmd, char ***argv)
{
	char *path, *base_path, *full_path, *path_ptr;

	path = _strdup(getenv("PATH"));
	path_ptr = path;
	base_path = strtok(path, ":");

	while (base_path != NULL)
	{
		full_path = malloc(_strlen(base_path) + 1 + _strlen(cmd) + 1);
		if (full_path == NULL)
			return (NULL);

		concat_str(full_path, "/", base_path, cmd);
		if (access(full_path, F_OK) == 0)
		{
			free(*argv[0]);
			*argv[0] = malloc(sizeof(char) * (_strlen(full_path) + 1));
			if (*argv[0] == NULL)
				return (NULL);

			_strcpy(*argv[0], full_path);
			free(path_ptr);
			return (full_path);
		}
		free(full_path);
		base_path = strtok(NULL, ":");
	}
	free(path_ptr);
	return (NULL);
}
