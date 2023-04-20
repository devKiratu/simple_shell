#include "main.h"
#define EXITCMD "exit"
#define ENVCMD "env"

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
		process_input(buffer, av[0], envp);
	}
	return (0);
}

/**
 * process_input - processes commands received via @buffer for execution
 * @buffer: pointer to command string
 * @name: name of executing program
 * @envp: environemnt vairables array
 * Return: void
 */
void process_input(char *buffer, char *name, char *envp[])
{
	unsigned int i;
	char **argv = create_argv(buffer);

	/* Check for `exit` command */
	if (strcmp(argv[0], EXITCMD) == 0)
	{
		if (argv[1] != NULL)
			exit(atoi(argv[1]));
		exit(0);
	}

	/* Check for 'env' command */
	if (strcmp(argv[0], ENVCMD) == 0)
	{
		for (i = 0; envp[i] != NULL; i++)
			printf("%s\n", envp[i]);
	}

	/* Check if argv[0] is a path or standalone command*/
	if (strstr(argv[0], "/") == NULL)
	{
		if (create_full_path(argv[0], &argv) == NULL)
		{
			/*TODO: handle error correctly*/
			printf("%s: No such file or directory\n", name);
		}
		else
		{
			execute_path(argv, name, envp);
		}
	}
	else
	{
		execute_path(argv, name, envp);
	}
}

/**
 * execute_path - does the actual execution of the processed commands
 * @argv: commands array
 * @name: name of the executing program
 * @envp: environment variables array
 * Return: void
 */
void execute_path(char *argv[], char *name, char *envp[])
{
	pid_t pid;

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
