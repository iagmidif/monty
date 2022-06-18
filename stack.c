#include "monty.h"

/**
 * _stack - sets the global variable stack_type to s
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _stack(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
	stack_type = 's';
}
