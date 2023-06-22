#include "monty.h"

/**
 * f_rotr - is a function for rotating last element of stack;
 * @head: is head node of stack;
 * @line_number: is a counts of line number;
 *
 * Return: nothing;
*/
void f_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int num;
	(void)line_number;

	while (current && current->next)
		current = current->next;

	while (current) /* moving in reverse */
	{
		num = current->n;
		if (current->prev)
		{
			current->n = (current->prev)->n;
			(current->prev)->n = num;
		}

		current = current->prev;
	}
}
