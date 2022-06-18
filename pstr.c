#include "monty.h"

/**
 * _pstr - prints the string at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;
	(void) line_num;

	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->prev;
	}
	putchar('\n');
}
