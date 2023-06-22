#include "monty.h"

/**
 * f_add - is a function to add two top values of stack;
 * @head: is double pointer of head node of stack;
 * @line_number: is count of line number;
 *
 * Return: nothing.
 */
void f_add(stack_t **head, int line_number)
{
	int sum;
	stack_t *current = *head;

	if (!(*head) || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(starg.file);
		free(starg.cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	sum = current->n + (current->next)->n;
	(current->next)->n = sum;
	*head = current->next;

	free(current);
}
