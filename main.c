#include "monty.h"

/**
 * main - entry point, see code
 * @argc: number of commands passed
 * @argv: pointer to an array of the commands used
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned int line_num = 1;
	char *line_buf = NULL;
	size_t line_len = 0;
	char *token;
	stack_t *stack;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line_buf, &line_len, fp) != -1)
	{
		token = strtok(line_buf, " \t\r\n\v\f");
		if (token != NULL && token[0] != '#')
			get_opcode_funcs(&stack, line_num, token);
		line_num++;
	}

	free_stack(stack);
	free(line_buf);
	fclose(fp);
	return (EXIT_SUCCESS);
}
