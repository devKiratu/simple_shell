#include "main.h"

/**
 * create_full_path - takes a command, and constructs its full if it exists
 * @cmd: command to create full path from
 * @argv: address of the commandline arguments to execute together with
 * Return: full path created or NULL in case of failure
 */
char *create_full_path(char *cmd, char ***argv)
{
	char *path, *base_path, *full_path;

	path = strdup(getenv("PATH"));
	base_path = strtok(path, ":");

	while (base_path != NULL)
	{
		full_path = malloc(strlen(base_path) + 1 + strlen(cmd) + 1);
		if (full_path == NULL)
			return (NULL);

		sprintf(full_path, "%s/%s", base_path, cmd);
		if (access(full_path, F_OK) == 0)
		{
			*argv[0] = malloc(sizeof(char) * (strlen(full_path) + 1));
			if (*argv[0] == NULL)
				return (NULL);

			strcpy(*argv[0], full_path);
			return (full_path);
		}
		free(full_path);
		base_path = strtok(NULL, ":");
	}
	return (NULL);
}
