#include "monty.h"

/**
 * op_mul - entry point
 *
 * Description: multiplies the second top elementof the stack
 * with the top element of the stack
 * @stack: pointer to ther pointer of the first element of the stack
 * @line_number: line number of the instruction
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	op_pop(stack, line_number);
}
