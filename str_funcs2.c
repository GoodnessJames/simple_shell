#include "shell.h"

char *_strchr(char *str, char c);
int _strspn(char *str, char *prefix);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _strchr - finds a character in a string
 * @str: The string to be searched
 * @c: The character to be located
 *
 * Return: Returns (s + index) if c is found
 *         If not found returns NULL
 */
char *_strchr(char *str, char c)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == c)
			return (str + i);
	}
	return (NULL);
}

/**
 * _strspn - Gets the length of a prefix substring
 * @str: The string to be searched
 * @prefix: The prefix to be measured
 *
 * Return: Returns the number of bytes in the string
 */
int _strspn(char *str, char *prefix)
{
	int i, bytes = 0;

	while (*str)
	{
		for (i = 0; prefix[i]; i++)
		{
			if (*str == prefix[i])
			{
				bytes++;
				break;
			}
		}
		str++;
	}
	return (bytes);
}

/**
 * _strcmp - Compares two strings
 * @s1: The first string to be compared
 * @s2: The second string to be compared
 *
 * Return: Returns (0) if s1 =s2 and (*s1 - *s2) if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - Compare n number of bytes in two strings
 * @s1: Pointer to a first string
 * @s2: Pointer to a second string
 * @n: n number of bytes to compare in a string
 *
 * Return: Returns (0) if s1 = s2
 *         Returns (s1[i] - s2[i]) if s1 is greater than s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
