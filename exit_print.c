#include "shell.h"

/**
 * exit_shell - This function closes the simple_shell.
 * @arg: Pointer to the argument.
 * @lineptr: Standard input string.
 * @_exit: Exit status.
 * Return: None.
 */
void exit_shell(char **arg, char *lineptr, int _exit)
{
	int exit_status = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(_exit);
	}
	exit_status = atoi(arg[1]);

	free(lineptr);
	free(arg);
	exit(exit_status);
}

/**
* print_environment - Function to print all environment variables.
* @env: Environment variables array.
* Return: None.
*/
void print_environment(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], _strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
