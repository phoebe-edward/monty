#include "monty.h"
/**
 * helping - helping function for the monty code interpreter
 *@args: pointer to main arguments and line number
 */
void helping(args_t *args)
{
	size_t len;
	int num;
	void (*func_ptr)(stack_t **, unsigned int);

	if (args->argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	data->file_ptr = fopen(args->argv, "r");
	if (data->file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", args->argv);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		data->line = NULL, data->word1 = NULL;
		num = getline(&(data->line), &len, data->file_ptr);
		if (num < 0)
			break;
		data->line[strcspn(data->line, "\n")] = '\0';
		args->line_num++;
		data->word1 = strtok(data->line, " ");
		if (data->word1 == NULL || data->word1[0] == '#')
		{
			free_all(0);
			continue;
		}
		func_ptr = func_choice();
		if (func_ptr == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				args->line_num, data->word1);
			free_all(0);
			exit(EXIT_FAILURE);
		}
		func_ptr(&(data->stack), args->line_num);
	}
	free_all(1);
}
