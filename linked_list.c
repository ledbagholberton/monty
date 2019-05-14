#include "monty.h"

/**
 * print_dlistint - print all nodes
 * @h: node
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int counter;

	if (!h)
		return (0);
	for (counter = 0; h; counter++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (counter);
}

/**
 * add_dnodeint - add node at the begginning
 * @head: node
 * @n: integer
 *
 * Return: addres of new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	if (!head)
		return (0);

	new_node = (dlistint_t *) malloc(sizeof(dlistint_t));
	if (!new_node)
		return (0);
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * free_dlistint - free nodes
 *@head: node
 *
 * Return: 0
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	if (!head)
		return;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * delete_dnodeint_at_index - delete at index
 * @head: head of node
 * @index: index to delete
 *
 * Return: 1 if success -1 else
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *temp;

	if (!head || !*head)
		return (-1);
	temp = *head;
	if (index == 0)
	{
		*head = temp->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	for (i = 0; i < index; i++)
	{
		if (!temp)
			return (-1);
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
