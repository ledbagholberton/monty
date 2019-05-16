#include "monty.h"

/**
 * exec_comp - execute
 * @tmp: command line
 * @head: head of list
 * @line: line number
 * Return: next line number
 */
void exec_comp(char *tmp, stack_t **head, unsigned int line)
{
	char *command;

	command = strtok(tmp, " \\n");
	tren.num_string = strtok(NULL, " \\n");
	if (command)
		(*get_op_func(command))(head, line);
}

/**
 * get_op_func - get the op function
 * @command: opcode
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
			return (ops[i].f);
	}

	return (ops[i].f);
}
