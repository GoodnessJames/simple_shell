#include "shell.h"

/**
 * _getenv - Gets an environmental variable from the PATH
 * @var: The name of the environmental variable to get
 *
 * Return: On SUCCESS, returns (value) ie a pointer to the environ variable
 *		   On FAILURE, returns (NULL) to indicate the variable does not exist
 */
char *_getenv(const char *var)
{
	char *value;
	int i, j;

	if (!var)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (var[j] == environ[i][j])
		{
			while (var[j])
			{
				if (var[j] != environ[i][j])
					break;

				j++;
			}
			if (var[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (NULL);
}

/**
 * _printenv - Prints the current environment
 * @av: Array of arguments
 */
void _printenv(char **av __attribute__ ((unused)))
{

	int i;

	if (!environ)
		return;
	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}

/**
 * _setenv - Adds or modifies an environment variable
 * @av: Array of arguments
 */
void _setenv(char **av)
{
	int i, j, k;

	if (!av[1] || !av[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (av[1][j] == environ[i][j])
		{
			while (av[1][j])
			{
				if (av[1][j] != environ[i][j])
					break;

				j++;
			}
			if (av[1][j] == '\0')
			{
				k = 0;
				while (av[2][k])
				{
					environ[i][j + 1 + k] = av[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = _strconcat(av[1], "=", av[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * _unsetenv - Remove an environment variable from the PATH
 * @av: Array of arguments
 */
void _unsetenv(char **av)
{
	int i, j;

	if (!av[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (av[1][j] == environ[i][j])
		{
			while (av[1][j])
			{
				if (av[1][j] != environ[i][j])
					break;

				j++;
			}
			if (av[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
