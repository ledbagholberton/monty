#include "monty.h"
/**
 * swap - swap the stack to the top
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */

void swap(stack_t **head, unsigned int n)
{
	stack_t *aux1, *aux2;

	if (*head == NULL || (*head)->next == NULL)
	{
		close(tren.fd);
		free(tren.buf);
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux1 = *head;
		aux2 = (*head)->next;
		*head = aux2;
		(*head)->prev = NULL;
		aux1->next = aux2->next;
		aux1->prev = *head;
		(*head)->next = aux1;
	}
}

/**
 * rotl - rotates the stack to the top
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */

void rotl(stack_t **head, unsigned int n)
{
	stack_t *aux1, *aux2;

	if (*head == NULL || (*head)->next == NULL)
		nop(head, n);
	else
	{
		aux1 = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		aux2 = *head;
		while (aux2->next != NULL)
			aux2 = aux2->next;
		aux2->next = aux1;
		aux1->next = NULL;
		aux1->prev = aux2;
	}
}
