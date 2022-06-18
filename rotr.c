#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *bottom;
	(void) line_num;

	if (*stack == NULL || (*stack)->prev == NULL)
		return;

	top = *stack;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	bottom = *stack;

	bottom->next->prev = NULL;
	bottom->next = NULL;
	bottom->prev = top;
	top->next = bottom;

	*stack = bottom;
}
