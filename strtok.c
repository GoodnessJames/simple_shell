#include "shell.h"

/**
 * splitStr - Splits a string into individual tokens
 * @str: The string to be split
 * @delim: The character used to indicate the end of a string
 *
 * Return: On SUCCESS, returns (array) i.e. a pointer to an array of str tokens
 *		   On FAILURE, returns (NULL)
 */

char **splitStr(char *str, const char *delim)
{
	char **array, *token, *input;
	int i, size;

	input = malloc(_strlen(str) + 1);
	if (input == 0)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		input[i] = str[i];
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
		array = _realloc(array, (sizeof(char *) * (size - 1)),
				(sizeof(char *) * size));
		if (array == 0)
		{
			return (NULL);
		}
		array[i] = _strdup(token);
		i++;
		size++;
	}
	free(input);
	return (array);
}
