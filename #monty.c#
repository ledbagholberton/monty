#include "monty.h"

extra_t tren = {NULL, NULL, 0};
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument value
 *
 * Return: 0 or exit error
 */
int main(int argc, char **argv)
{
	int num_letters, j, i;
	char tmp[1000];
	stack_t *head;
	unsigned int line = 0;

	tren.buf = malloc(sizeof(char) * 100024);
	tren.buf[100023] = '\0';
	head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(tren.buf);
		exit(EXIT_FAILURE); }
	tren.fd = open(argv[1], O_RDONLY);
	if (!argv[1] || tren.fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(tren.buf);
		exit(EXIT_FAILURE); }
	num_letters = read(tren.fd, tren.buf, sizeof(char) * 100024);
	if (num_letters == -1)
	{
		free(tren.buf);
		return (0); }
	j = 0;
	while (tren.buf[j] != '\0')
	{
		i = 0;
		for (; tren.buf[j] != '\n' && tren.buf[j] != '\0'; j++, i++)
			tmp[i] = tren.buf[j];
		tmp[i] = '\0';
		if (tmp[0] != '\0' && tmp[0] != '\n')
		{
			line++;
			exec_comp(tmp, &head, line); }
		j++; }
	close(tren.fd);
	free_dlistint(head);
	free(tren.buf);
	return (0);
}
