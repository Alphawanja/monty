#include "monty.h"

/**
 * op_pall - entry point
 *
 * Description: prints out all the values of the stack
 *
 * @stack: address of the stack to print
 * @line_number: line number of the opcode being executed
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *arr = *stack;

	while (arr)
	{
		printf("%d\n", arr->n);
		arr = arr->next;
	}

	(void)line_number;
}
