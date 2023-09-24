#include "monty.h"
/**
 * _swap - swaps the top two elemnts of the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_curr1 = NULL, *stack_curr2 = NULL, *stack_temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	stack_curr1 = *stack;
	if (stack_curr1->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	stack_curr2 = stack_curr1->next;
	stack_temp = stack_curr2->next;
	if (stack_temp != NULL)
	{
		stack_temp->prev = stack_curr1;
		stack_curr1->next = stack_temp;
	}
	else
	{
		stack_curr1->next = NULL;
	}
	stack_curr2->next = stack_curr1;
	stack_curr1->prev = stack_curr2;
	stack_curr2->prev = NULL;
	data->stack = stack_curr2;
	*stack = stack_curr2;
}
