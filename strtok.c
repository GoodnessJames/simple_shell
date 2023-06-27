#include "shell.h"

int _toklen(char *str, char *delim);
int _tokcount(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * _toklen - Finds the delimiter marking the end of a string
 * @str: The string to be obtain the len
 * @delim: The delimiter
 *
 * Return: Returns (len) ie the delimiter len
 */
int _toklen(char *str, char *delim)
{
	int i = 0, len = 0;

	while (*(str + i) && *(str + i) != *delim)
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * _tokcount - Counts the number of delimited words in a string
 * @str: The string to count
 * @delim: The delimiter
 *
 * Return: Returns (token) ie the number of words in a line of strings
 */
int _tokcount(char *str, char *delim)
{
	int i, tokens = 0, len = 0;

	for (i = 0; *(str + i); i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != *delim)
		{
			tokens++;
			i += _toklen(str + i, delim);
		}
	}

	return (tokens);
}

/**
 * _strtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: Returns a pointer to an array of the tokenized words
 */
char **_strtok(char *line, char *delim)
{
	int i = 0, tokens, t, letters, l;
	char **ptr;

	tokens = _tokcount(line, delim);
	if (tokens == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tokens + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < tokens; t++)
	{
		while (line[i] == *delim)
			i++;

		letters = _toklen(line + i, delim);

		ptr[t] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[t])
		{
			for (i -= 1; i >= 0; i--)
				free(ptr[i]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
		{
			ptr[t][l] = line[i];
			i++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
