#include "shell.h"

void free_args(char **args, char **arg0);
char *get_pid(void);
char *env_value(char *var, int len);
void replace_var(char **args, int *ret);

/**
 * free_args - Frees up memory taken by args
 * @args: A 2D pointer to the commands entered
 * @arg0: A 2D pointer to the start of the arguments
 */
void free_args(char **args, char **arg0)
{
	size_t i;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(arg0);
}

/**
 * get_pid - Gets the current process ID of the shell
 *
 * Return: On SUCCESS, returns (pid) ie the current process ID
 *		   On FAILURE, returns (NULL)
 */
char *get_pid(void)
{
	char *pid;
	size_t i = 0;
	ssize_t file;

	file = open("/proc/self/stat", O_RDONLY);
	if (file == -1)
	{
		perror("Cant read file");
		return (NULL);
	}
	pid = malloc(120);
	if (!pid)
	{
		close(file);
		return (NULL);
	}
	read(file, pid, 120);
	while (pid[i] != ' ')
		i++;
	pid[i] = '\0';
	close(file);

	return (pid);
}

/**
 * env_value - Gets the value associated to an environment variable
 * @var: The environment variable to search for
 * @len: The length of the environment variable to search for
 *
 * Return: On SUCCESS, returns (env_fetched) ie the value of the env variable
 *		   On FAILURE, returns (NULL) to indicate env variable is not found
 *
 */
char *env_value(char *var, int len)
{
	char *i, *env_name, **env_addr, *env_fetched = NULL;

	env_name = malloc(len + 1);
	if (!env_name)
		return (NULL);
	env_name[0] = '\0';
	_strncat(env_name, var, len);

	env_addr = _getenv(env_name);
	free(env_name);
	if (env_addr)
	{
		i = *env_addr;
		while (*i != '=')
			i++;
		i++;
		env_fetched = malloc(_strlen(i) + 1);
		if (env_fetched)
			_strcpy(env_fetched, i);
	}
	return (env_fetched);
}

/**
 * replace_var - Handles variable replacement
 * @args: A 2D pointer containing the command line arguments
 * @ret: A pointer to the return value of the last command
 */
void replace_var(char **args, int *ret)
{
	int len, i, j = 0;
	char *new_line, *old_line = NULL, *value = NULL;

	old_line = *args;
	for (i = 0; old_line[i]; i++)
	{
		if (old_line[i] == '$' && old_line[i + 1] && old_line[i + 1] != ' ')
		{
			if (old_line[i + 1] == '$')
			{
				value = get_pid();
				j = i + 2;
			}
			else if (old_line[i + 1] == '?')
			{
				value = _itoa(*ret);
				j = i + 2;
			}
			else if (old_line[i + 1])
			{
				j = i + 1;
				while (old_line[j] && old_line[j] != '$' && old_line[j] != ' ')
					j++;
				len = j - (i + 1);
				value = env_value(&old_line[i + 1], len);
			}
			new_line = malloc(i + _strlen(value) + _strlen(&old_line[j]) + 1);
			if (!args)
				return;
			new_line[0] = '\0';
			_strncat(new_line, old_line, i);
			if (value)
			{
				_strcat(new_line, value);
				free(value);
				value = NULL;
			}
			_strcat(new_line, &old_line[j]);
			free(old_line);
			*args = new_line;
			old_line = new_line;
			i = -1;
		}
	}
}
