#include "monty.h"

/**
 * stack - execute
 * @head: command line
 * @line: head of list
 *
 * Return: next line number
 */
void stack(stack_t **head, unsigned int line)
{
	(void) line;
	(void) head;

	tren.opcode = "stack";
}

/**
 * queue - execute
 * @head: command line
 * @line: head of list
 *
 * Return: next line number
 */
void queue(stack_t **head, unsigned int line)
{
	(void) line;
	(void) head;

	tren.opcode = "queue";
}

/**
 * add_dnodeint_end - add node at the end
 * @head: node
 * @n: string
 *
 * Return: number of nodes
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *reference;
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
	new_node->next = NULL;
	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}
	reference = *head;
	while (reference->next)
		reference = reference->next;
	reference->next = new_node;
	new_node->prev = reference;

	return (new_node);
}
