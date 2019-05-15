#include "monty.h"

/**
 * exec_comp - execute
 * @tmp: command line
 * @head: head of list
 *
 * Return: void
 */
void exec_comp (char *tmp, stack_t **head)
{
	char *command, *digit;
	unsigned int parameter;

	command = strtok(tmp, " ");
	digit = strtok(NULL, " ");
	if (digit)
		parameter = atoi(digit);
	else
		parameter = 0;

	(*get_op_func(command))(head, parameter);
/*	printf("command %s\n", command);
	printf("Parameter %s\n", parameter);*/
}

/**
 * get_op_function - get the op function
 * @head: command
 *
 * Return: No -  0 if fail or call the function
 */
void (*get_op_func(char *command))(stack_t **head, unsigned int parameter)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", push},
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
	add_dnodeint(head, n);
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
