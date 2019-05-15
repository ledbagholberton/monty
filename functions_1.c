#include "monty.h"


/**
 * push - function to add at the head
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */

void push(stack_t **head, unsigned int n)
{
	int number;
	unsigned int flag = 1, i;

	if (tren.num_string)
	{
		for (i = 0; tren.num_string[i] != '\0'; i++)
		{
			if (tren.num_string[i] >= 48 &&
			    tren.num_string[i] <= 57)
				flag = 0;
			else
				flag = 1;
		}
		if (flag == 0)
			number = atoi(tren.num_string);
		else
		{
			close(tren.fd);
			free(tren.buf);
			free_dlistint(*head);
			fprintf(stderr, "L%d: usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(tren.fd);
		free(tren.buf);
		free_dlistint(*head);
		fprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}

	add_dnodeint(head, number);
}

/**
 * pall - function to print all
 * @head: head of list
 * @n: line number in 0
 *
 * Return: 0 or error code
 */

void pall(stack_t **head, unsigned int n)
{
	stack_t *head1;

	head1 = *head;
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
	(void) n;
	head1 = *head;
	print_head(head1);
}
