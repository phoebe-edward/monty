#include "monty.h"
/**
 * func_choice - choose function based on opcode
 * Return: function pointer to chosen func
 */
void (*func_choice(void))(stack_t **, unsigned int)
{
	instruction_t inst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{NULL, NULL}
	};
	int opcodes = 8, i;

	for (i = 0; i < opcodes; i++)
	{
		if (strcmp(inst[i].opcode, data->word1) == 0)
			return (inst[i].f);
	}
	return (NULL);
}
/**
 * free_all - free all string arrays
 * @all: if 1 close file and empty stack
 */
void free_all(int all)
{
	if (data->line != NULL)
		free(data->line);
	if (all == 1)
	{
		if (data->file_ptr)
		{
			fclose(data->file_ptr);
			data->file_ptr = NULL;
		}
		if (data->stack)
		{
			free_stack();
			data->stack = NULL;
		}
	}
}
/**
 * free_stack - free data.stack
 */
void free_stack(void)
{
	stack_t *str_curr = NULL;

	if (data->stack)
	{
		str_curr = data->stack;
		while (str_curr->next != NULL)
		{
			str_curr = str_curr->next;
			free(str_curr->prev);
		}
		free(str_curr);
	}
}
