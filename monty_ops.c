#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_file - read bytecode file
 * @name: name of file
 * @stack: pointer to the stack
 */

void read_file(char *name, stack_t **stack)
{
	char *buf = NULL;
	char *stack_line;
	int count = 1;
	FILE *file = fopen(name, "r");
	size_t i = 0;
	int check;
	instruct_func op;

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", name);
		sterr_exit(stack);
	}
	while (getline(&buf, &i, file) != -1)
	{
		stack_line = line_parse(buf);
		if (stack_line == NULL || stack_line[0] == '#')
		{
			count++;
			continue;
		}
		op = get_func(stack_line);
		if (op == NULL)
		{
			printf("L%d: unknown instruction %s\n", count, stack_line);
			sterr_exit(stack);
		}
		op(stack, count);
		count++;
	}
	free(buf);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}

/**
 * get_func - returns the function for an opcode
 * @str: the opcode
 * Return: returns corresponding function or NULL
 */

instruct_func get_func(char *str)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL},
	};

	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}
	return (instruct[i].f);
}

/**
 * line_parse - returns an opcode from a line
 * @line: line to be tokenized
 * Return: returns the opcode or NUll
 */
char *line_parse(char *line)
{
	char *opcode;

	opcode = strtok(line, "\n ");
	if (opcode == NULL)
		return (NULL);
	return (opcode);
}
