#include "monty.h"

/**
 * mul - function to multiply
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */
void mul(stack_t **head, unsigned int n)
{
	stack_t *head1;

	head1 = *head;
	if (!head1 || !head1->next)
	{
		close(tren.fd);
		free(tren.buf);
		fprintf(stderr, "L%d: can't mul, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;

	pop(head, n);
}
