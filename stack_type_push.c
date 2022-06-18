#include "monty.h"

/**
 * push_s - uses LIFO
 * @stack: double pointer to the top of the stack
 * @data: data to be pushed
 *
 * Return: void, nth
 */
void push_s(stack_t **stack, int data)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = data;
	new->next = NULL;
	if (*stack == NULL)
		new->prev = NULL;
	else
	{
		new->prev = *stack;
		(*stack)->next = new;
	}
	*stack = new;
}

/**
 * push_q - uses FIFO
 * @stack: double pointer to the top of the stack
 * @data: data to be pushed
 *
 * Return: void, nth
 */
void push_q(stack_t **stack, int data)
{
	stack_t *new, *bottom;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = data;
	new->prev = NULL;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		bottom = *stack;
		while (bottom->prev != NULL)
			bottom = bottom->prev;
		new->next = bottom;
		bottom->prev = new;
	}
}
