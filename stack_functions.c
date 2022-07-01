#include "monty.h"

/**
 * _push - push an element to the stack
 * @stack: pointer to dl-list for the stack
 * @line_number: number of line used up in the stack
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newline;
	char *av;
	int push_av;

	push_av = 0;
	newline = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		printf("Error: malloc failed\n");
		sterr_exit(stack);
	}
	av = strtok(NULL, "\n");
	if (isnumber(av) == 1 && av != NULL)
	{
		push_av = atoi(av);
	}
	else
	{
		printf("L%i: usage: push integer\n", line_number);
		sterr_exit(stack);
	}
	if (flag == 1)
	{
		add_dnodeint_end(stack, push_av);
	}
	if (flag == 0)
	{
		add_dnodeint(stack, push_av);
	}
}

/**
 * _pall - print all values on the stack
 * @stack: pointer to the dl-list of the stack
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - print the top stack data
 * @stack: pointer to the dl-list of the stack
 * @line_number: number of lines in the stack
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		sterr_exit(stack);
	}
	printf("%d\n", temp->n);
}

/**
 * _pop - delete data at the top of stack
 * @stack: pointer to the dl-list of the stack
 * @line_number: number of lines in the stack
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		sterr_exit(stack);
	}
	delete_dnodeint_at_index(stack, 0);
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to the dl-list of the stack
 * @line_number: number of lines in the stack
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int data;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		sterr_exit(stack);
	}
	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;
}
