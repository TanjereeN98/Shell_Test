#include "shell.h"

/**
 * tokens_count - count the number of tokens within a string >> "/bin/ls -l -p"
 * @str: the string to be parsed
 * @delim: the delimeter to check for
 *
 * Return: returns the number of tokens within a string
 */

int tokens_count(char *str, char *delim)
{
	int tokens = 0, len, index = 0;

	len = _strlen(str);
	for (index ; index < len ; index++)
	{
		if (str[index] == *delim)
		{
			tokens++;
		}
	}
	return (tokens);
}
