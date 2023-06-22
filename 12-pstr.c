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
	int c;
	(void)line_number;

	while (*head)
	{
		c = (*head)->n;
		if (c <= 0 || c > 127)
			break;
		putchar(c);
		*head = (*head)->next;
	}

	putchar('\n');
}
