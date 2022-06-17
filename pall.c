#include "monty.h"

/**
 * _pall - prints all the values on the stack
 * uses LIFO, starting form the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *node;

	(void) line_num;
	node = *stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
}
