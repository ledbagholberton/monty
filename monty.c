#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument value
 *
 * Return: 0 or exit error
 */

int num;
int main(int argc, char **argv)
{
	
	int fd, num_letters, j, i;
	char tmp[1000];
	char *buf = malloc(sizeof(char) * 1024);
	stack_t *head;
	unsigned int line = 0;

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
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
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
		if (buf[j + 1] != '\0' || buf[j] != '\n' || buf[j] != 0)
		{
			tmp[i] = '\0';
			printf("%s\n", tmp);
			line++;
			exec_comp(tmp, &head, line);
		}
		j++;
	}

	close(fd);
	free_dlistint(head);
	free(buf);
	return (0);
}
