#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
