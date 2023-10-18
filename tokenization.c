#include "shell.h"

/**
 * tokenize_line - Tokenizes a user's command line input.
 * @lineptr: User's command line input.
 *
 * Return: An array of tokenized strings.
 */
char **tokenize_line(char *lineptr)
{
	char **command_tokens = NULL;
	char *token = NULL;
	size_t i = 0;
	int token_count = 0;

	if (lineptr == NULL)
		return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			token_count++;
	}
	if ((token_count + 1) == _strlen(lineptr))
		return (NULL);

	command_tokens = malloc(sizeof(char *) * (token_count + 2));
	if (command_tokens == NULL)
		return (NULL);

	token = _strtok(lineptr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		command_tokens[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	command_tokens[i] = NULL;

	return (command_tokens);
}
