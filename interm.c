#include "monty.h"

/**
 * inter_monty - monty interpreter
 * @av: argument vector
 * Return: nothing
 */
void inter_monty(char **av)
{
	char *fl = av[1], *buffer = NULL, **tokens = NULL;
	size_t len = 0, lin = 1;
	ssize_t r_line;
	stack_t *s_stack = NULL;
	FILE *open_f;

	open_f = fopen(fl, "r");

	if (open_f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fl);
		exit(EXIT_FAILURE);
	}

	for (lin = 1; (r_line = getline(&buffer, &len, open_f)) != -1; lin++)
	{
		token_line(&buffer, &tokens, r_line);
		if (tokens != NULL)
			opcode_choose(&s_stack, &tokens, lin);
		freetokens(&tokens);
	}

	fclose(open_f);
	if (buffer != NULL)
		free(buffer);
	freest_stack(s_stack);
}

/**
 * freetokens - free the tokens
 * @tokens: tokens to free
 * Return: nothing
 */
void freetokens(char ***tokens)
{
	if (*tokens != NULL)
	{
		free(*tokens);
		*tokens = NULL;
	}
}

/**
 * freest_stack - free the stack
 * @s_stack: stack to free
 * Return: nothing
 */
void freest_stack(stack_t *s_stack)
{
	stack_t *savep;

	if (s_stack != NULL)
	{
		while (s_stack != NULL)
		{
			savep = s_stack->next;
			free(s_stack);
			s_stack = savep;
		}
	}
}
