#include "monty.h"

/**
 * f_push - a function to add a new element at stack;
 * @head: is a head node of stack;
 * @line_number: is number counted inside stack;
 *
 * Return: nothing.
 */
void f_push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (starg.args)
	{
		if (starg.args[0] == '-')
			j++;
		for (; starg.args[j] != '\0'; j++)
		{
			if (starg.args[j] > 57 || starg.args[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(starg.file);
			free(starg.cont);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(starg.file);
		free(starg.cont);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	n = atoi(starg.args);
	if (starg.stqu == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * f_pall - is a function for printing or displaying stack elements;
 * @head: is head node of stack;
 * @line_number: not used;
 * Return: nothing.
*/
void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *head;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
