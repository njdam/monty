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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	f_parser(file);
	fclose(file);

	return (EXIT_SUCCESS);
}
