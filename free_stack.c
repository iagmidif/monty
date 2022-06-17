#include "main.h"

/**
 * free_stack - frees a stack
 * @stack: the stack to be freed
 *
 * Return: void, nth
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
