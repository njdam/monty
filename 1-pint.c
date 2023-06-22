#include "monty.h"
/**
 * f_pint - is a function for printing the top value of stack;
 * @head: is head node of stack;
 * @line_number: is a counts of line number;
 * Return: nothing;
*/
void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(starg.file);
		free(starg.cont);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
