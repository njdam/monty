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
	char line[100]; /* buffer to hold line limit */
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); }
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
			f_push(&stack, line_number); }
		else if (strcmp(starg.args, "pall") == 0)
			f_pall(&stack, line_number);
		else if (strcmp(starg.args, "pint") == 0)
			f_pint(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, starg.args);
			fclose(starg.file);
			free(starg.cont);
			free_stack(stack);
			exit(EXIT_FAILURE); }
	}
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
