#include "monty.h"
/**
 * _pop - pops the upper most element form the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_curr = NULL, *stack_temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	stack_curr = *stack;
	while (stack_curr->next != NULL)
	{
		stack_curr = stack_curr->next;
	}
	stack_temp = stack_curr->prev;
	if (stack_temp == NULL)
		data->stack = NULL;
	else
		stack_temp->next  = NULL;
	free(stack_curr);
}
