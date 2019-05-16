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
	void (*exec)(stack_t **head, unsigned int n);

	command = strtok(tmp, " ");
	tren.num_string = strtok(NULL, " ");
	if (command)
		exec = get_op_func(command);
	if (exec == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, command);
		close(tren.fd);
		free(tren.buf);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	exec(head, line);
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
	int i, len;

	len = strlen(command);
	for (i = 0; ops[i].opcode; i++)
	{
		if (strncmp((ops[i].opcode), command, len) == 0)
			return (ops[i].f);
	}

	return (ops[i].f);
}