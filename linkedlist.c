#include "shell.h"

/**
 * add_endnode - Adds a node to the end of a list_path linked list.
 * @head: A pointer to the head of the list_path list
 * @path: The directory path for the new node
 *
 * Return: Returns (endnode) on SUCCESS and (NULL) on FAILURE
 */
list_path *add_endnode(list_path **head, char *path)
{
	list_path *tmp;
	list_path *endnode = malloc(sizeof(list_path));

	if (!endnode)
		return (NULL);

	endnode->dir = path;
	endnode->next = NULL;

	if (*head)
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = endnode;
	}
	else
		*head = endnode;

	return (endnode);
}

/**
 * free_list - Frees a list_path linked list
 * @head: The head of the list_path list
 */
void free_list(list_path *head)
{
	list_path *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
}
}
