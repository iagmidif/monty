#include "monty.h"

/**
 * _queue - sets the global variable stack_type to q
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _queue(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
	stack_type = 'q';
}
