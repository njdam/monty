#include "monty.h"

/**
 * f_pstr - is a function for printing character at the top of stack;
 * @head: is head node of stack;
 * @line_number: is a counts of line number;
 *
 * Return: nothing;
*/
void f_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void)line_number;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
