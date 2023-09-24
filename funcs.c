#include "monty.h"
/**
 * func_choice - choose function based on opcode
 * @words: words obtained from line
 * Return: function pointer to chosen func
 */
void (*func_choice(char **words))(stack_t **, unsigned int)
{
	instruction_t inst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};
	int opcodes = 3, i;

	for (i = 0; i < opcodes; i++)
	{
		if (strcmp(inst[i].opcode, words[0]) == 0)
			return (inst[i].f);
	}
	return (NULL);
}
/**
 * free_all - free all string arrays
 * @all: 0 or 1 (0 for line and words only, 1 for file_ptr and stack too
 */
void free_all(int all)
{
	if (all == 0)
	{
		if (data->words != NULL)
		{
			if (data->words[0] != NULL)
				free(data->words[0]);
			free(data->words);
		}
		if (data->line != NULL)
			free(data->line);
	}
	else if (all == 1)
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
