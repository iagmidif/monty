#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;
	int temp;
	(void) line_num;

	if (*stack == NULL)
		return;

	top = *stack;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	bottom = *stack;
	
	*stack = top;
	while (top != bottom && top > bottom)
	{
		temp = top->n;
		top->n = bottom->n;
		bottom->n = temp;

		top = top->prev;
		bottom = bottom->next;
	}
}
