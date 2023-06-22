#include "monty.h"

/**
 * f_rotl - is a function for rotating top element of stack;
 * @head: is head node of stack;
 * @line_number: is a counts of line number;
 *
 * Return: nothing;
*/
void f_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int num;
	(void)line_number;

	while (current)
	{
		num = current->n;
		if (current->next)
		{
			current->n = current->next->n;
			current->next->n = num;
		}

		current = current->next;
	}
}
