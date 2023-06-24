#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @str: A pointer to the string
 *
 * Return: Returns (len)
 */
int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len])
	{
		len++;
	}
	return (len);
}

/**
 * _strdup - Creates a new dynamically allocated copy of a string
 * @str: Pointer to an array of characters (string)
 *
 * Return: On SUCCESS, returns (new) ie a pointer to the new space in memory
 *		   On FAILURE, returns (NULL)
 */
char *_strdup(char *str)
{
	char *new;
	int i, len;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		new[i] = str[i];
	}
	new[len] = str[len];
	return (new);
}

/**
 * _strconcat - Joins three strings
 * @cmd: The command
 * @delim: The seperator
 * @value: The value
 *
 * Return: Returns pointer to the new string
 */
char *_strconcat(char *cmd, char *delim, char *value)
{
	char *result;
	int len1, len2, len3, i, k;

	len1 = _strlen(cmd);
	len2 = _strlen(delim);
	len3 = _strlen(value);

	result = malloc(len1 + len2 + len3 + 1);
	if (!result)
		return (NULL);
	for (i = 0; cmd[i]; i++)
		result[i] = cmd[i];
	k = i;
	for (i = 0; delim[i]; i++)
		result[k + i] = delim[i];
	k = k + i;
	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 *
 * Return: On SUCCESS, returns (1)
 *		   On FAILURE, returns (-1) and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string
 * @str: The string to be printed
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
