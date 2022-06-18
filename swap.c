#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: double pointer to the top the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_num);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = temp;
}
