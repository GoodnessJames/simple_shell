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
