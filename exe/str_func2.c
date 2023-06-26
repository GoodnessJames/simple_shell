#include "shell.h"

/**
 * _atoi - Converts a string to an integer
 * @str: Pointer to a string
 *
 * Return: On SUCCESS, returns the converted integer (n * sign)
 */

int _atoi(char *str)
{
	int sign = 1;
	unsigned int n = 0;

	do {
		if (*str == '-')
			sign *= -1;
		else if (*str >= '0' && *str <= '9')
			n = (n * 10) + (*str - '0');
		else if (n > 0)
			break;
	} while (*str++);

	return (n * sign);
}
