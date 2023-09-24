#include "monty.h"
/**
 * _pall - prints all stack elements
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *stack1 = NULL;

	if (stack == NULL || *stack == NULL)
		return;
	stack1 = *stack;
	while (stack1 != NULL)
	{
		printf("%d\n", stack1->n);
		stack1 = stack1->next;
	}
	(void)line_number;
}
