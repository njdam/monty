#include "monty.h"

/**
 * f_nop - is a function doesn't do anything in a stack;
 * @head: is double pointer of head node of stack;
 * @line_number: is count of line number;
 *
 * Return: nothing.
 */
void f_nop(stack_t **head, unsigned int line_number)
{
	(void)(*head);
	(void)line_number;
}
