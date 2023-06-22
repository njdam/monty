#include "monty.h"

/**
 * f_mul - is a function to multiply two top elements of stack;
 * @head: is double pointer of head node of stack;
 * @line_number: is count of line number;
 *
 * Return: nothing.
 */
void f_mul(stack_t **head, int line_number)
{
	int result;
	stack_t *current = *head;

	if (!(*head) || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(starg.file);
		free(starg.cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = (current->next)->n * current->n;
	(current->next)->n = result;
	*head = current->next;

	free(current);
}
