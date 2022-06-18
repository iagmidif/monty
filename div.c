#include "monty.h"

/**
 * _div - divides the second top element by the top element of the stack
 * The result is stored in the second top element of the stack
 * and the top element is removed
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _div(stack_t **stack, unsigned int line_num)
{
	int quotient;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_num);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	quotient = (*stack)->prev->n / (*stack)->n;
	_pop(stack, line_num);
	(*stack)->n = quotient;
}
