#include "monty.h"

/**
 * f_parser - a function to pass argument for call it's function;
 * @file: is a monty file containing monty command line arguments;
 *
 * Return: nothing.
 */
void f_parser(FILE *file)
{
	char line[100]; /* buffer to hold line limit */
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	starg.file = file; /* for Settind file pointer in starg */
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		starg.args = strtok(line, " \n"); /* for extracting first argument */
		if (starg.args == NULL || starg.args[0] == '#')
			continue; /* for skipping empty line and comment */
		if (strcmp(starg.args, "push") == 0)
		{
			starg.args = strtok(NULL, " \n"); /* to extract second argument */
			f_push(&stack, line_number);
		}
		else if (strcmp(starg.args, "pall") == 0)
			f_pall(&stack, line_number);
		else if (strcmp(starg.args, "pint") == 0)
			f_pint(&stack, line_number);
		else if (strcmp(starg.args, "pop") == 0)
			f_pop(&stack, line_number);
		else if (strcmp(starg.args, "swap") == 0)
			f_swap(&stack, line_number);
		else if (strcmp(starg.args, "add") == 0)
			f_add(&stack, line_number);
		else if (strcmp(starg.args, "nop") == 0)
			f_nop(&stack, line_number);
		else if (strcmp(starg.args, "sub") == 0)
			f_sub(&stack, line_number);
		else if (strcmp(starg.args, "div") == 0)
			f_div(&stack, line_number);
		else if (strcmp(starg.args, "mul") == 0)
			f_mul(&stack, line_number);
		else
			errorcode(stack, line_number);
	}
	free_stack(stack);
}

/**
 * errorcode - a function for printing error code;
 * @stack: is a pointer of head node of stack;
 * @line_number: is count number of line;
 *
 * Return: nothing.
 */
void errorcode(stack_t *stack, int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, starg.args);
	fclose(starg.file);
	free(starg.cont);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
