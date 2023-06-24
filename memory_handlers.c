#include "shell.h"

/**
 * _realloc - Reallocates memory for the block
 * @pt: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 *
 * Return: On SUCCESS, returns (new) ie the pointer to the new memory
 *		   On FAILURE, returns (NULL)
 */

void *_realloc(void *pt, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *new, *old;
	void *tmp = NULL;

	if (pt == 0)
	{
		tmp = (malloc(new_size));
		if (tmp == 0)
			return (NULL);
		return (tmp);
	}
	if (new_size == old_size)
		return (pt);

	if (new_size == 0 && pt != 0)
	{
		free(pt);
		return (NULL);
	}

	new = malloc(new_size);
	old = pt;
	if (new == 0)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(pt);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(pt);
	}
	return (new);
}

/**
 * free_av - Frees an array of strings
 * @av: The array of strings
 */

void free_av(char **av)
{
	int i = 0;

	while (av[i])
	{
		i++;
		free(av[i]);
	}
	free(av);
}
