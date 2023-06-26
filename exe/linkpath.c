#include "shell.h"

/**
 * linkpath - Creates a linked list for directories in a given path
 * @path: The string representing the path value
 *
 * Return: On SUCCESS, returns (head) ie the pointer to the linked list
 */
list_path *linkpath(char *path)
{
	char *token;
	char *pathdup = _strdup(path);
	list_path *head = NULL;

	token = strtok(pathdup, ":");
	while (token)
	{
		head = add_endnode(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}

/**
 * add_endnode - Adds a new node at the end of a list_path linked list
 * @head: Pointer to the first node of the linked list
 * @path: The directory location for the new node
 *
 * Return: On SUCCESS, returns (*head) ie address of the new node
 *		   On FAILURE, returns (NULL) to indicate an error occured
 */

list_path *add_endnode(list_path **head, char *path)
{

	list_path *tmp, *endnode;

	endnode = malloc(sizeof(list_path));

	if (!endnode || !path)
		return (NULL);

	endnode->dir = path;
	endnode->next = NULL;
	if (!*head)
		*head = endnode;
	else
	{
		tmp = *head;

		while (tmp->next)
			tmp = tmp->next;
		tmp->next = endnode;
	}
	return (*head);
}


/**
 * free_list - Frees the list_path linked list
 *@head: Pointer to the first node of the linked list
 */
void free_list(list_path *head)
{
	list_path *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->dir);
		free(head);
		head = tmp;
	}
}

/**
 * findpath - Locates the PATH of a command
 * @cmd: The name of the command to locate its path
 * @head: The pointer to the first node of the linked list
 *
 * Return: On SUCCESS, returns (path) ie the path of the command
 *		   On FAILURE, returns (NULL)
 */
char *findpath(char *cmd, list_path *head)
{
	struct stat st;
	char *path;
	list_path *tmp = head;

	while (tmp)
	{
		path = _strconcat(tmp->dir, "/", cmd);
		if (path == 0)
		{
			return (NULL);
		}
		if (stat(path, &st) == 0)
			return (path);
		free(path);
		tmp = tmp->next;
	}
	return (NULL);
}
