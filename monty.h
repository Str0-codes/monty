#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define BUFSIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int flag;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void(*instruct_func)(stack_t **stack, unsigned int line_number);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t count);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
void sterr_exit(stack_t **head);
int main(int argc, char **argv);
void _push(stack_t **stack, unsigned int line_number);
int isnumber(char *str);
int _isdigit(int c);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void read_file(char *name, stack_t **stack);
instruct_func get_func(char *str);
char *line_parse(char *line);


#endif
