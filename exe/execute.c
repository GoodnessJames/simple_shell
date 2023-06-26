#include "shell.h"

/**
 * execute - Executes the command entered in the command line
 * @args: Array of arguments
 *
 * Return: Returns nothing (void)
 */

void execute(char **args)
{
	int status;
	pid_t pid;

	if (!args || !args[0])
		return;
	pid = fork();
	if (pid == -1)
	{
		perror(_getenv("_"));
	}
	if (pid == 0)
	{
		execve(args[0], args, environ);
			perror(args[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
