#include "monty.h"

int flag = 0;
/**
 * main - the entry point for monty
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		sterr_exit(&stack);
	}
	read_file(argv[1], &stack);
	free_dlistint(stack);
	return (0);
}
