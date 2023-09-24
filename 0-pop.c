#include "monty.h"
/**
 * _pop - pops the upper most element form the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_curr = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	stack_curr = *stack;
	if ((*stack)->next == NULL)
	{
		*stack = NULL;
		data->stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		data->stack = (*stack);
		(*stack)->prev = NULL;
	}
	free(stack_curr);
}
