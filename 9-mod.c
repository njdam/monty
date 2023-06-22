#include "monty.h"

/**
 * f_mod - is a function to find remainder of top elements of stack;
 * @head: is double pointer of head node of stack;
 * @line_number: is count of line number;
 *
 * Return: nothing.
 */
void f_mod(stack_t **head, unsigned int line_number)
{
	int result;
	stack_t *current = *head;

	if (!(*head) || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(starg.file);
		/*free(starg.cont);*/
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(starg.file);
		/*free(starg.cont);*/
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	result = (current->next)->n % current->n;
	(current->next)->n = result;
	*head = current->next;

	free(current);
}
