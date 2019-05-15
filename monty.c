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
		fprintf(stderr, "USAGE: monty file\n");
		free(buf);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);

	if (!argv[1] || fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
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
	free_dlistint(head);
	free(buf);
	return (0);
}
