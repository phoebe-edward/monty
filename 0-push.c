#include "monty.h"
#include <unistd.h>
/**
 * _push - push elements in stack
 * @stack: stack pointer to pointer
 * @line_number: unsigned int line num
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *stack1 = NULL;
	stack_t *str_curr = NULL;

	stack1 = malloc(sizeof(stack_t));
	if (stack1 == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (data->words[1] == NULL || is_int(data->words[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack == NULL || *stack == NULL)
	{
		stack1->next = NULL;
		stack1->prev = NULL;
		stack1->n = atoi(data->words[1]);
		stack = &stack1;
		data->stack = stack1;
	}
	else
	{
		str_curr = *stack;
		while (str_curr->next != NULL)
		{
			str_curr = str_curr->next;
		}
		str_curr->next = stack1;
		stack1->prev = str_curr;
		stack1->next = NULL;
		stack1->n = atoi(data->words[1]);
	}
}
/**
 * is_int - checks wether the given string is an integer or not
 * @str: string to be checked
 * Return: 0 if not int, 1 if int
 */
int is_int(char *str)
{
	int i;

	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	for (; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}
