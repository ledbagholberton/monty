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
	char *command, *parameter;

	command = strtok(tmp, " ");
	parameter = strtok(NULL, " ");
	(*get_op_func(command))(head, atoi(parameter));
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
		{"pall", push},
		{"pint", push},
		{"nop", push},
		{NULL, NULL}
	};
	int i;
	
	for (i = 0; i <= 4; i++)
	{
		if (strcmp((ops[i].opcode), command) == 0)
			return(ops[i].f);
	}
	return(ops[3].f);
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
