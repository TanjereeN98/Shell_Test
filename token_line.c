#include "shell.h"

/**
 * token_line - function to tokenize the input.
 * @line: the buffer line read to be tokenized.
 * Return: pointer to array of strings.
 */

char **token_line(char *line)
{
	char *token = NULL, *buff_dup = NULL, *delim = " ";
	char **tokens = NULL;
	int len = 0, buffsize = 64, index = 0;

	buff_dup = _strdup(line);
	tokens = malloc(buffsize * sizeof(char *));
	if (!tokens)
	{
		write(STDERR_FILENO, "Allocation Error\n", 17);
		exit(EXIT_FAILURE);
	}
	token = strtok(buff_dup, delim);
	while (token != NULL)
	{
		tokens[len] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!tokens[len])
		{
			for (index ; index <= buffsize ; index++)
				free(tokens[index]);
			free(tokens);
			write(STDERR_FILENO, "Allocation Error\n", 17);
			exit(EXIT_FAILURE);
		}
		_strcpy(tokens[len], token);
		len++;
		token = strtok(NULL, delim);
	}
	tokens[len] = NULL;
	free(buff_dup);
	return (tokens);
}


/**char **token_line(char *line)
{
	char *token, *buff_dup = NULL, *delim = " ";
	char **tokens = NULL;
	int len = 0, index = 0, buffsize = 0, letters = 0;

	buff_dup = _strdup(line);
	buffsize = tokens_count(buff_dup, delim);
	tokens = malloc((buffsize + 1) * sizeof(char *));
	if (!tokens)
	{
		write(STDERR_FILENO, "Allocation Error\n", 17);
		exit(EXIT_FAILURE);
	}
	token = strtok(buff_dup, " ");
	while (token != NULL)
	{
		letters = _strlen(token);
		tokens[len] = malloc(sizeof(char) * (letters + 1));
		if (!tokens[len])
		{
			for (index ; index <= buffsize ; index++)
				free(tokens[index]);
			free(tokens);
			write(STDERR_FILENO, "Allocation Error\n", 17);
			exit(EXIT_FAILURE);
		}
		_strcpy(tokens[len], token);
		len++;
		token = strtok(NULL, " ");
	}
	tokens[len] = NULL;
	free(buff_dup);
	return (tokens);
}*/