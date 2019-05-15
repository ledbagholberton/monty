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
 * Return: 0 if fail or call the function
 */
int (*get_op_function(char *command))(stack_t **head, int parameter)
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
		{
			ops[i].f;
			return (1);
		}
	}
	return(0);
}



/**
 * push - function to add at the head
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */

stack_t *push(stack_t **head, unsigned int n)
{
	add_dnodeint(head, n);
	return (*head);
}
