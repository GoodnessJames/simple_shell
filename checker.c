#include "shell.h"

/**
 * check_input - verifies if input us from the terminal
 * Return: nothing (void)
 */
void check_input(void)
{
	if (isatty(STDIN_FILENO))
		_puts(":) ");
}

/**
 * check_EOF - checks if the current position is end of file
 * @len: the return value of getline function
 * @buffer: the temporal storage for holding data
 *
 * Return: Nothing (void)
 */
void check_EOF(int len, char *buffer)
{
	(void)buffer;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}

/**
 * check_sig - verifies if ctrl c key combination is pressed
 * @sig: the int variable to compare to SIGINT
 *
 * Return: nothing (void)
 */
void check_sig(int sig)
{
	if (sig == SIGINT)
	{
		_puts("\n:) ");
	}
}
