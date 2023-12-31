#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @str: A pointer to the characters string
 *
 * Return: The length of the character string.
 */
int _strlen(const char *str)
{
	int len = 0;

	if (!str)
		return (len);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

/**
 * _strcpy - Copies a string from src to desc buffer
 * @dest: The destination of copied string
 * @src: The source string
 *
 * Return: Returns (dest);
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: Returns (dest)
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int destLen = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
		dest[destLen + i] = src[i];
	dest[destLen + i] = '\0';

	return (dest);
}

/**
 * _strncat - Concatenates n bytes of two strings
 * @dest: The destination string
 * @src: The source string
 * @n: n bytes to copy from src
 *
 * Return: Returns (dest) ie the destination string
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t destLen = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[destLen + i] = src[i];
	dest[destLen + i] = '\0';

	return (dest);
}
