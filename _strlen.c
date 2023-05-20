#include "shell.h"

/**
 * _strlen -  a function that returns the length of a string.
 * @s: input parameter pointer to char
 * Return: returns the length of the provided string
 */

int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	if (*s != '\0')
		return (1 + _strlen(s + 1));
	return ('\n');
}
