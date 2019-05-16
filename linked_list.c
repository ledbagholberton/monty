#include "monty.h"

/**
 * print_dlistint - print all nodes
 * @h: node
 *
 * Return: number of nodes
 */
size_t print_dlistint(const stack_t *h)
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
 * print_head - print Top node
 * @h: node
 *
 * Return: number of nodes
 */
size_t print_head(const stack_t *h)
{
	if (!h)
		return (0);
	printf("%d\n", h->n);
	return (0);
}


/**
 * add_dnodeint - add node at the begginning
 * @head: node
 * @n: integer
 *
 * Return: addres of new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (!head)
		return (0);

	new_node = (stack_t *) malloc(sizeof(stack_t));
	if (!new_node)
	{
		close(tren.fd);
		free(tren.buf);
		free_dlistint(*head);
		exit(0);
	}
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
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

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
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int i;
	stack_t *temp;

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
