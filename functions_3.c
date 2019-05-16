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

/**
 * pstr - function to print string
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */
void pstr(stack_t **head, unsigned int n)
{
	stack_t *head1;

	head1 = *head;
	(void) n;
	while (head1 != NULL)
	{
		if (head1->n >= 64 && head1->n <= 123)
			printf("%c", (char)head1->n);
		else
			break;
		head1 = head1->next;
	}
	printf("\n");
}

/**
 * rotr - function to print all
 * @head: head of list
 * @n: line number in 0
 *
 * Return: 0 or error code
 */

void rotr(stack_t **head, unsigned int n)
{
	stack_t *temp;
	stack_t *tail;



	if (*head == NULL || (*head)->next == NULL)
		nop(head, n);
	else
	{
		temp = NULL;
		tail = *head;
		while (tail != NULL)
		{
			temp = tail;
			tail = tail->next;
		}
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = *head;
		*head = temp;
	}
}
