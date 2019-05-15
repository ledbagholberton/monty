#include "monty.h"

/**
 * exec_comp - execute
 * @tmp: command line
 * @head: head of list
 * @line: line number
 * Return: next line number
 */
void exec_comp (char *tmp, stack_t **head, unsigned int line)
{
	char *command, *digit;
	unsigned int flag, i;

	flag = 0;
	command = strtok(tmp, " ");
	digit = strtok(NULL, " ");
	if (digit)
	{
		for (i = 0; digit[i] != '\0'; i++)
		{
			if (digit[i] >= 48 && digit[i] <= 57)
				flag = 0;
			else
				flag = 1;
		}
		if (flag == 0)
			num = atoi(digit);
		else
		{
			fprintf(stderr, "L%d: usgae: push integer",line);
			exit (EXIT_FAILURE);
		}
	}
	(*get_op_func(command))(head, line);
}

/**
 * get_op_function - get the op function
 * @head: command
 *
 * Return: No -  0 if fail or call the function
 */
void (*get_op_func(char *command))(stack_t **head, unsigned int line)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;
	for (i = 0; i <= 4; i++)
	{
		if (strcmp((ops[i].opcode), command) == 0)
			return(ops[i].f);
	}

	return(ops[i].f);
}


/**
 * push - function to add at the head
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */

void push(stack_t **head, unsigned int n)
{
	add_dnodeint(head, num);
	(void) n;
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
