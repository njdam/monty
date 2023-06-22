#include "monty.h"

/**
 * f_swap - is a function to swap two top values of stack;
 * @head: is double pointer of head node of stack;
 * @line_number: is count of line number;
 *
 * Return: nothing.
 */
void f_swap(stack_t **head, unsigned int line_number)
{
	int num;

	if (!(*head) || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(starg.file);
		/*free(starg.cont);*/
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	num = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = num;
}
