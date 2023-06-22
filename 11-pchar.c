#include "monty.h"

/**
 * f_pchar - is a function for printing character at the top of stack;
 * @head: is head node of stack;
 * @line_number: is a counts of line number;
 *
 * Return: nothing;
*/
void f_pchar(stack_t **head, unsigned int line_number)
{
	int c;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(starg.file);
		free(starg.cont);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	c = (*head)->n;
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(starg.cont);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	putchar(c);
	putchar('\n');
}
