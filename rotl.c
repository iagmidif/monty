#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;
	(void) line_num;

	if (*stack == NULL || (*stack)->prev == NULL)
		return;

	top = *stack;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	bottom = *stack;
	*stack = top->prev;

	top->next = bottom;
	top->prev = NULL;
	bottom->prev = top;

	(*stack)->next = NULL;
}
