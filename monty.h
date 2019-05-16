#ifndef MONTY_H
#define  MONTY_H

#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * struct extra_s - doubly linked list representation of a stack (or queue)
 * @num_string: string of num
 * @str: points to the previous element of the stack (or queue)
 * @buf: buffer
 * @fd: number file
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct extra_s
{
	char *num_string;
	char *buf;
	int fd;
	char *opcode;
} extra_t;

extern extra_t tren;

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


void errors(int argc, char **argv);
void pint(stack_t **head, unsigned int n);
size_t print_dlistint(const stack_t *h);
size_t print_head(const stack_t *h);
void (*get_op_func(char *command))(stack_t **head, unsigned int parameter);
void exec_comp(char *tmp, stack_t **head, unsigned int line);
void push(stack_t **head, unsigned int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void pall(stack_t **head, unsigned int n);
void nop(stack_t **head, unsigned int n);
void pop(stack_t **head, unsigned int n);
void add(stack_t **head, unsigned int n);
void sub(stack_t **head, unsigned int n);
void swap(stack_t **head, unsigned int n);
void rotl(stack_t **head, unsigned int n);
void div_func(stack_t **head, unsigned int n);
void mul(stack_t **head, unsigned int n);
void mod(stack_t **head, unsigned int n);
void pchar(stack_t **head, unsigned int n);
void pstr(stack_t **head, unsigned int n);
void rotr(stack_t **head, unsigned int n);
void stack(stack_t **head, unsigned int line);
void queue(stack_t **head, unsigned int line);
stack_t *add_dnodeint_end(stack_t **head, const int n);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


#endif /*  MONTY_H */
