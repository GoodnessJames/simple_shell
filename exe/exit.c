#include "shell.h"

/**
 * shellexit - Terminates program execution of the shell
 * @av: Array of arguments entered in the command line
 */
void shellexit(char **av)
{
	int i, num;

	if (av[1])
	{
		num = _atoi(av[1]);
		if (num < 0)
			num = 2;
		free_av(av);
		exit(num);
	}
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	exit(0);
}
