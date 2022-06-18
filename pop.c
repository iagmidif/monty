#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	free(*stack);
	*stack = temp;
}
