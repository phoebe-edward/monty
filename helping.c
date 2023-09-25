#include "monty.h"
/**
 * helping - helping function for the monty code interpreter
 *@args: pointer to main arguments and line number
 */
void helping(args_t *args)
{
	size_t len;
	void (*func_ptr)(stack_t **, unsigned int);

	while (1)
	{
		data->line = NULL, data->word1 = NULL;
		if (getline(&(data->line), &len, data->file_ptr) < 0)
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
		if (func_ptr == NULL ||
		    (strcmp(data->word1, "push") != 0 && strtok(NULL, " ")))
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				args->line_num, data->word1);
			if (args != NULL)
				free(args);
			free_all(1);
			exit(EXIT_FAILURE);
		}
		func_ptr(&(data->stack), args->line_num);
	}
	if (args != NULL)
		free(args);
	free_all(1);
}
