#include "shell.h"

/**
 * main - Calls all the functions required for the execution
 *		  of the simple command line interpreter
 *
 * Return: Returns (0) on SUCCESS
 */
int main(void)
{
	char **args, *value, *cmdpath, *buffer = NULL;
	list_path *head = NULL;
	size_t size = 0;
	ssize_t len = 0;
	void (*fpt)(char **);

	signal(SIGINT, check_sig);
	while (len != EOF)
	{
		check_input();
		len = getline(&buffer, &size, stdin);
		check_EOF(len, buffer);
		args = splitStr(buffer, " \n");
		if (!args || !args[0])
			execute(args);
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			cmdpath = findpath(args[0], head);
			fpt = checkbuiltin(args);
			if (fpt)
			{
				free(buffer);
				fpt(args);
			}
			else if (!cmdpath)
				execute(args);
			else if (cmdpath)
			{
				free(args[0]);
				args[0] = cmdpath;
				execute(args);
			}
		}
	}
	free_list(head);
	free_av(args);
	free(buffer);
	return (0);
}
