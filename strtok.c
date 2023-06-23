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
