#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument value
 *
 * Return: 0 or exit error
 */
int main(int argc, char **argv)
{
	int fd, num_letters, j, i;
	char tmp[10];
	char *buf = malloc(sizeof(char) * 1024);
	stack_t *head;

	head = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		free(buf);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);

	if (!argv[1] || fd == -1)
	{
		printf("Error: Can't open file %s", argv[1]);
		free(buf);
		exit (EXIT_FAILURE);
	}

	num_letters = read(fd, buf, sizeof(char) * 1024);

	if (num_letters == -1)
	{
		free(buf);
		return (0);
	}

	j = 0;
	while(buf[j] != '\0')
	{
		i = 0;
		for(; buf[j] != '\n'; j++, i++)
			tmp[i] = buf[j];

		tmp[i] = '\0';
		exec_comp(tmp, &head);
		j++;
	}

	print_dlistint(head);
	num_letters = write(STDOUT_FILENO, buf, num_letters);
	if (num_letters == -1)
	{
		free(buf);
		return (0);
	}


	close(fd);
	free_list(head);
	free(buf);
	return (0);
}

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
	(*get_op_func(command))(atoi(parameter));
/*	printf("command %s\n", command);
	printf("Parameter %s\n", parameter);*/
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
	stack_t *new_node;

	if (!head)
		return (0);

	new_node = (stack_t *) malloc(sizeof(stack_t));
	if (!new_node)
		return (0);
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * get_op_function - get the op function
 * @head: command
 *
 * Return: 0 if fail or call the function
 */
int (*get_op_function(char *command))(stackt_t **head, int parameter)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", print_dlistint},
		{NULL, NULL}
	};

	int i;

	for (i = 0; i <= 2; i++)
	{
		if (*(ops[i].opcode) == *command)
		{
			return(ops[i].f);
		}
	}
	return(0);
}
