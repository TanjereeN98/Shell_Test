#include "shell.h"
/**
 * _strdup - function that returns pointer to duplicated string
 * @str: the string that will be duplicated
 * Return: pointer to char
 */
char *_strdup(char *str)
{
	int size, i;
	char *ptr = NULL;

	if (!str)
		return (NULL);
	for (size = 0 ; str[size] != '\0' ; size++)
		;
	ptr = malloc((size + 1) * sizeof(*str));

	if (ptr == NULL)
		return (NULL);
	for (i = 0 ; i < size ; i++)
		ptr[i] = str[i];
	return (ptr);
}
