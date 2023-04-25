#include "main.h"
#define EXITCMD "exit"
#define ENVCMD "env"
#define SETENV "setenv"
#define UNSETENV "unsetenv"

/**
 * main - entry point to shell
 * @ac: arguments count
 * @av: arguments array
 * @envp: environment variables vector
 * Return: 0 success
 */
int main(int ac __attribute__((unused)), char *av[], char *envp[])
{
	char *buffer, **argv;
	size_t n;
	ssize_t count = 0;

	while (count != -1)
	{
		printf("#cisfun$ ");

		count = getline(&buffer, &n, stdin);
		argv = create_argv(buffer);
		process_input(argv, av[0], envp);
	}
	free(buffer);
	free(argv);
	return (0);
}

/**
 * process_input - processes commands received via @buffer for execution
 * @argv: pointer to command string
 * @name: name of executing program
 * @envp: environemnt vairables array
 * Return: void
 */
void process_input(char **argv, char *name, char *envp[])
{
	/* handle special commands e.g. exit, setenv, unsetenv etc */
	if (handle_special_commands(argv, name) == 0)
		return;

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
 * handle_special_commands - checks for commands, executable as they are
 * @argv: commands array
 * @name: name of executing program
 * Return: 0 if any command is executed, 1 if none is executed
 */
int handle_special_commands(char **argv, char *name)
{
	unsigned int i;
	/* check for setenv */
	if (strcmp(argv[0], SETENV) == 0)
	{
		_setenv(argv, name);
		return (0);
	}
	/* Check for unsetenv */
	if (strcmp(argv[0], UNSETENV) == 0)
	{
		_unsetenv(argv, name);
		return (0);
	}
	/* Check for `exit` command */
	if (strcmp(argv[0], EXITCMD) == 0)
	{
		if (argv[1] != NULL)
			exit(atoi(argv[1]));
		free(argv);
		exit(0);
	}
	/* Check for 'env' command */
	if (strcmp(argv[0], ENVCMD) == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
		return (0);
	}
	return (1);
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
	free(argv);
}
