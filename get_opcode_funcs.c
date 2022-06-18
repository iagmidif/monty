#include "monty.h"

/**
 * get_opcode_funcs - executes the function associated with the opcode
 * @stack: double pointer to the top of the stack
 * @line_num: line number of the code
 * @token: token/opcode to map
 *
 * Return: void, nth
 */
void get_opcode_funcs(stack_t **stack, unsigned int line_num, char *token)
{
	int i = 0;
	instruction_t opcode_func[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}
	};

	while (opcode_func[i].opcode)
	{
		if (strcmp(opcode_func[i].opcode, token) == 0)
		{
			opcode_func[i].f(stack, line_num);
			return;
		}
		i++;
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_num, token);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
