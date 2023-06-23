#include "monty.h"

/**
 * f_stack - is a function to suitch to switch back to stack;
 * @head: is double pointer of head node of stack;
 * @line_number: is count of line number;
 *
 * Return: nothing.
*/
void f_stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	starg.stqu = 0;
}

/**
 * f_queue - is a function to suitch to queue;
 * @head: is double pointer of head node of stack;
 * @line_number: is count of line number;
 *
 * Return: nothing.
*/
void f_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	starg.stqu = 1;
}
