#include "shell.h"

/**
 * splitstr - splits a string into individual tokens
 * @str: the string to be split
 * @delim: character used to indicate end of string
 * Return: on SUCCESS, returns (array) i e a pointer to an array
 * of string of token otherwise return (NULL) on failure
 */
char **splitstr(char *str, const char *delim)
{
	char **array, *token, *input;
	int i, size;

	input = malloc(strlen(str) + 1);
	if (imput == 0)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while(str[i])
	{
		input [i] = str[i];
		i++;
	}
	input[i] = '\0';

	token = strtok(input, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	size = 3;
	i = 1;
	while (token)
	{
		token = strtok(NULL, delim);
		array = _realloc(array, sizeof(char *) * (size - 1)),
		      ((sizeof(char *) * size));
		if (array == 0)
		{
			free(array);
			return (NULL);
		}
		array[i] = _strdup(token);
		i++;
		size++;
	}
	free(input);
	return (array);
}
