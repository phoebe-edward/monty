#include "monty.h"
/**
 * _pint - print the value at the top of the stack followed by a new line
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
