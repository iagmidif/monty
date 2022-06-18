#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * The result is stored in the second top element of the stack
 * and the top element is removed
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _add(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_num);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->prev->n;
	_pop(stack, line_num);
	(*stack)->n = sum;
}
