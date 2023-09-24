#include "monty.h"
/**
 * _pint - print the value at the top of the stack followed by a new line
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_curr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_curr = *stack;
	while (stack_curr->next != NULL)
	{
		stack_curr = stack_curr->next;
	}
	printf("%d\n", stack_curr->n);
}
