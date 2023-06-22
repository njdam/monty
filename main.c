#include "monty.h"

/**
 * main - refernced main function;
 * @argc: is number of command line arguments;
 * @argv: is arguments on command line;
 * Return: value 0.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line;
	stack_t *stack = NULL;
	size_t size = 0;
	ssize_t yes = 1;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	starg.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (yes > 0)
	{
		line = NULL;
		yes = getline(&line, &size, file);
		starg.cont = line;
		line_number++;
		if (yes > 0)
			f_opcode(&stack, line_number);
		free(line);
	}
	free_stack(&stack);
	fclose(file);

	/*return (EXIT_SUCCESS);*/
	return (0);
}

/**
 * f_opcode - a function to pass argument for call it's function;
 * @stack: is a pointer of head node of stack;
 * @line_number: is count number of line;
 *
 * Return: nothing.
 */
int f_opcode(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode_t[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
		{"nop", f_nop}, {"sub", f_sub}, {"div", f_div},
		{"mul", f_mul}, {"mod", f_mod}, {NULL, NULL}
	};
	char *ops;
	unsigned int i = 0;

	ops = strtok(starg.cont, " \n\t"); /* for extracting first args as opcode */
	if (ops && ops[0] == '#')
		return (0); /* to handle comments (10-comments.c) */

	starg.args = strtok(NULL, " \n\t"); /* to extract second argument */
	while (opcode_t[i].opcode && ops)
	{
		if (strcmp(ops, opcode_t[i].opcode) == 0)
		{
			opcode_t[i].f(stack, line_number);
			return (0);
		}
		i++;
	}

	if (opcode_t[i].opcode == NULL && ops)
	{
		starg.args = ops;
		errorcode(stack, line_number);
	}

	return (1);
}

/**
 * errorcode - a function for printing error code;
 * @stack: is a pointer of head node of stack;
 * @line_number: is count number of line;
 *
 * Return: nothing.
 */
void errorcode(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, starg.args);
	fclose(starg.file);
	free(starg.cont);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
