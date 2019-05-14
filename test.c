#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;




void exec_comp(char *);
stack_t *push(stack_t **head, unsigned int n);
size_t print_dlistint(const stack_t *h);

int main(int argc, char **argv)
{
	int fd, num_letters, j, i;
	char tmp[10];
	char *buf = malloc(sizeof(char) * 1024);

	fd = open(argv[1], O_RDONLY);
	(void) argc;

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
		exec_comp(tmp);
		j++;
	}

	num_letters = write(STDOUT_FILENO, buf, num_letters);
	if (num_letters == -1)
	{
		free(buf);
		return (0);
	}

	close(fd);
	free(buf);
	return (0);
}


void exec_comp (char *tmp)
{
	char *command, *parameter;
	stack_t *head;

	command = strtok(tmp, " ");
	parameter = strtok(NULL, " ");
	(void) command;
	push(&head, atoi(parameter));
	print_dlistint(head);
/*	printf("command %s\n", command);
	printf("Parameter %s\n", parameter);*/
}

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

size_t print_dlistint(const stack_t *h)
{
	int counter;

	if (!h)
		return (0);
	printf("This is the linked list\n");
	for (counter = 0; h; counter++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (counter);
}
