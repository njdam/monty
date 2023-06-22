#include "monty.h"

/**
* free_stack - is a function to free doubly linked list of stack;
* @head: is head node of the stack;
*
* Return: nothing.
*/
void free_stack(stack_t **head)
{
	stack_t *current;

	current = *head;
	while (*head)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
}
