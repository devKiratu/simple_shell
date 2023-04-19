#include "main.h"
#define EXITCMD "exit"

/**
 * main - entry point to shell
 * @ac: arguments count
 * @av: arguments array
 * @envp: environment variables vector
 * Return: 0 success
 */
int main(int ac __attribute__((unused)), char *av[], char *envp[])
{
	char *buffer;
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
		execute_path(buffer, av[0], envp);
	}
	return (0);
}

/**
 * execute_path - executes command in @path via execve
 * @buffer: pointer to command string
 * @name: name of executing program
 * @envp: environemnt vairables array
 * Return: void
 */
void execute_path(char *buffer, char *name, char *envp[])
{
	pid_t pid;
	char **argv = create_argv(buffer);

	/* Check for `exit` command */
	if (strcmp(argv[0], EXITCMD) == 0)
		exit(0);

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
