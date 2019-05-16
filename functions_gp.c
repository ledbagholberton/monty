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
	stack_t aux1, aux2;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr,"L%d: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	else
	{
		aux1 = head;
		aux2 = head->next;
		head = aux2;
		head->prev = NULL;
		aux1->next = aux2->next;
		aux1->prev = head;
		head->next = aux1;
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
	stack_t aux1, aux2, aux3;

	if (head == NULL || head->next == NULL)
		nop (head, n);
	else
	{
		aux1 = head;
		head = head->next;
		head->prev = NULL;
		aux2 = head;
		while (aux2->next != NULL)
			aux2 = aux2->next;
		aux2->next = aux1;
		aux1->next = NULL;
		aux1->prev = aux2;
	}
}

/**
 * rotr - function to rot all the stack
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */

void rotr(stack_t **head, unsigned int n)
{
	stack_t *aux1, *aux2;

	aux1 = *head;
	aux2 = *head;
	while (aux2->next != NULL)
		aux2 = aux2->next;
	
	(void) n;
	print_dlistint(head1);
}

/**
 * nop - function to do nothing
 * @head: head of list
 * @n: line number in 0
 *
 * Return: 0 or error code
 */

void nop(stack_t **head, unsigned int n)
{
	(void) n;
	(void) head;
	printf("Nop\n");
}

/**
 * pint - function to print head
 * @head: head of list
 * @n: line number in 0
 *
 * Return: 0 or error code
 */

void pint(stack_t **head, unsigned int n)
{
	stack_t *head1;

	head1 = *head;
	if (!head1)
	{
		close(tren.fd);
		free(tren.buf);
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	print_head(head1);
}

void pop(stack_t **head, unsigned int n)
{
	stack_t *head1;

	head1 = *head;
	if (!head1)
	{
		close(tren.fd);
		free(tren.buf);
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	free(head1);
	if (*head)
		(*head)->prev = NULL;
}
