#include "monty.h"

/**
 * m_pint - prints value on top of 'stack', or exit if stuck is empty
 * @stack: double pointer to the head of stack
 * @line_number: line of current operation
 *
 * Return: void
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}
