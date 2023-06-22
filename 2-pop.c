#include "monty.h"

/**
 * f_pop - is a function to delete top value of stack;
 * @head: is double pointer of head node of stack;
 * @line_number: is count of line number;
 *
 * Return: nothing.
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(starg.file);
		free(starg.cont);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	*head = current->next;
	if (*head)
	{
		(*head)->prev = NULL;
		if (current->next != NULL)
			(*head)->next = (current->next)->next;
	}

	free(current);
}
