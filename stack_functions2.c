#include "monty.h"

/**
 * _nop - do nothing
 * @stack: pointer to the dl-list of the stack
 * @line_number: the number of the current stack
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}
