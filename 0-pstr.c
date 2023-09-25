#include "monty.h"
/**
 * _pstr - print ASCII string of the stack followed by a new line
 * @stack: pointer to pointer to stack
 * @line_number: line number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_curr = NULL;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	stack_curr = *stack;
	while (stack_curr != NULL)
	{
		if (stack_curr->n + '\0' > 127 || stack_curr->n + '\0' <= 0)
		{
			break;
		}
		printf("%c", stack_curr->n + '\0');
		stack_curr = stack_curr->next;
	}
	printf("\n");
	(void)line_number;
}
