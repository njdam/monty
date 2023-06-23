#include "monty.h"

/**
 * addnode - is a function to add node at head node of stack;
 * @head: is double pointer to head node of stack;
 * @n: is a value to be added at the start of stack;
 *
 * Return: nothing.
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (current)
		current->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * addqueue - is a function to add node at the tail of stack;
 * @n: a value to be added at the tail of stack;
 * @head: is double pointer to head node of stack;
 *
 * Return: nothing.
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;

	if (current)
	{
		while (current->next)
			current = current->next;
	}

	if (!current)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current->next = new_node;
		new_node->prev = current;
	}
}
