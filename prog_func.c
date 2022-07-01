#include "monty.h"

/**
 * sterr_exit - free and exit stack on error
 * @stack: pointer to the stack
 */

void sterr_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * _isdigit - check for digit between 0 1nd 9
 * @c: the digit to be checked
 * Return: 1 if digit, 0 if otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/**
 * isnumber - check if string is an integer
 * @str: string to be checked
 * Return: 1 if integer, 0 if not integer
 */

int isnumber(char *str)
{
	unsigned int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
