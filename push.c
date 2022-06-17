#include "monty.h"

/**
 * _push - pushes a node to the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 *
 * Return: void, nth
 */
void _push(stack_t **stack, unsigned int line_num)
{
	size_t i, len;
	char val[128] = "";
	char *value = val;
	stack_t *new;

	value = strtok(NULL, " \t\r\n");
	if (value == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	len = strlen(value);
	for (i = 0; i < len; i++)
	{
		if (!isdigit(value[i]) && value[0] != '-')
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->n = atoi(value);
	if (*stack == NULL)
		new->prev = NULL;
	else
	{
		new->prev = *stack;
		(*stack)->next = new;
	}
	*stack = new;
}
