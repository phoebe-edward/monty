#include "monty.h"
/**
 * _rotr - rotate
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_curr = NULL, *stack_last = NULL;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	if ((*stack)->next == NULL)
		return;
	stack_curr = *stack;
	stack_last = *stack;
	while (stack_last->next != NULL)
		stack_last = stack_last->next;
	(stack_last->prev)->next = NULL;
	stack_last->next = stack_curr;
	stack_last->prev = NULL;
	stack_curr->prev = stack_last;
	*stack = stack_last;
	data->stack = stack_last;
	(void)line_number;
}
