#include "monty.h"
/**
 * add_dnodeint - add a node at the start of dl-list
 * @head: pointer to the first node
 * @n: data in the node
 * Return: pointer to the node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	if (head == NULL)
	{
		newnode->n = n;
		newnode->prev = NULL;
		newnode->next = NULL;
		*head = newnode;
		return (*head);
	}
	(*head)->prev = newnode;
	newnode->n = n;
	newnode->next = *head;
	newnode->prev = NULL;
	*head = newnode;
	return (*head);
}

/**
 * add_dnodeint_end - add a new node at the end of a dl-list
 * @head: pointer to the list
 * @n: data in the node
 * Return: pointer to the node
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *newnode, *temp;

	newnode = malloc(sizeof(stack_t));
	temp = *head;
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = n;

	if (*head == NULL)
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		*head = newnode;
		return (newnode);
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->prev = temp;
	newnode->next = NULL;
	return (newnode);
}

/**
 * delete_dnodeint_at_index - delete node at position
 * @head: pointer to the list
 * @index: index of the node
 * Return: 1 if successful, -1 if failed
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp, *temp2;
	unsigned int i;

	if (*head == NULL)
	{
		return (-1);
	}
	temp = *head;
	if (index == 0)
	{
		*head = temp->next;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		free(temp);
		return (1);
	}
	i = 0;
	while (i < (index - 1))
	{
		if (temp == NULL)
			return (-1);
		temp = temp->next;
		i++;
	}
	temp2 = temp->next->next;
	if (temp->next->next != NULL)
		temp->next->next->prev = temp;
	free(temp->next);
	temp->next = temp2;
	return (1);
}

/**
 * free_dlistint - frees a list
 * @head: pointer to the list
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
