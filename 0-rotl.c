#include "monty.h"
/**
 * _rotl - rotate
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _rotl(stack_t **stack, unsigned int line_number)
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
	*stack = stack_curr->next;
	(*stack)->prev = NULL;
	data->stack = *stack;
	stack_last->next = stack_curr;
	stack_curr->prev = stack_last;
	stack_curr->next = NULL;
	(void)line_number;
}
