#include "main.h"

/**
 * main - entry point to shell
 * @ac: arguments count
 * @av: arguments array
 * @envp: environment variables vector
 * Return: 0 success
 */
int main(int ac, char *av[], char *envp[])
{
	char *buffer, *token;
	size_t n = 8;
	ssize_t count = 0;

	buffer = malloc(sizeof(char) * n);
	if (buffer == NULL)
	{
		perror("Error");
		exit(1);
	}

	while (count != -1)
	{
		printf("#cisfun$ ");

		count = getline(&buffer, &n, stdin);
		token = strtok(buffer, " \n");
		execute_path(token, av[0], envp);
	}
	(void)ac;
	return (0);
}

/**
 * execute_path - executes command in @path via execve
 * @path: absolute path of command to execute
 * @name: name of executing program
 * @envp: environemnt vairables array
 * Return: void
 */
void execute_path(char *path, char *name, char *envp[])
{
	pid_t pid;
	char *argv[2];

	argv[0] = path;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
		perror("Error");
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			perror(name);
	}

	wait(NULL);
}
