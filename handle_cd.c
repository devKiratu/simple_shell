#include "main.h"

/**
 * handle_cd - Handles cd system call
 * @s: Optional paramenter for cd
 *
 * Return: Success status of cd
 */
int handle_cd(char *s)
{
	char *term;
	int status = 0;

	if (s != NULL)
	{
		if (_strcmp(s, "-") == 0)
			term = _getenv("OLDPWD");
		else if (_strcmp(s, "~") == 0)
			term = _getenv("HOME");
		else
			term = s;
	}
	else
	{
		term = _getenv("HOME");
	}
	if (term[0] == '=')
		term++;
	status = chdir(term);
	return (status);
}
