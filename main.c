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
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.file_ptr = fopen(args->argv, "r");
	if (data.file_ptr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", args->argv);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		num = getline(&data.line, &len, data.file_ptr);
		if (num < 0)
			break;
		args->line_num++;
		data.words = _strtok(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_all(0);
			continue;
		}
		func_ptr = func_choice(data.words);
		if (func_ptr == NULL)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
				args->line_num, data.words[0]);
			free_all(0);
			exit(EXIT_FAILURE);
		}
		func_ptr(&(data.stack), args->line_num);
		free_all(0);
	}
	free_all(1);
}
/**
 * main - entry point
 * @argv: arguments pointer
 * @argc: argument count
 * Return: always 0
 */
int main(int argc, char **argv)
{
	args_t *args = NULL;

	args->argv = argv[1];
	args->argc = argc;
	args->line_num = 0;

	data.file_ptr = NULL;
	data.line = NULL;
	data.words = NULL;

	helping(args);
	return (EXIT_SUCCESS);
}
