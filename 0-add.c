#include "monty.h"
/**
 * _add- adds the top two elemnts of the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_curr1 = NULL, *stack_curr2 = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	stack_curr1 = *stack;
	if (stack_curr1->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	stack_curr2 = stack_curr1->next;
	while (stack_curr2->next != NULL)
	{
		stack_curr1 = stack_curr1->next;
		stack_curr2 = stack_curr2->next;
	}
	stack_curr1->n = stack_curr1->n + stack_curr2->n;
	stack_curr1->next = NULL;
	free(stack_curr2);
}
