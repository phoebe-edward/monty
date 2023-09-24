#include "monty.h"
/**
 * main - entry point
 * @argv: arguments pointer
 * @argc: argument count
 * Return: always 0
 */
data_t *data = NULL;
int main(int argc, char **argv)
{
	args_t *args = NULL;

	args = malloc(sizeof(args_t));
	if (args == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	args->argv = argv[1];
	args->argc = argc;
	args->line_num = 0;
	data = malloc(sizeof(data_t));
	if (data == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	data->file_ptr = NULL;
	data->line = NULL;
	data->word1 = NULL;
	data->stack = NULL;
	if (args->argc != 2)
	{
		if (args != NULL)
			free(args);
		free_all(1);
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	data->file_ptr = fopen(args->argv, "r");
	if (data->file_ptr == NULL)
	{
		if (args != NULL)
			free(args);
		free_all(1);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	helping(args);
	return (EXIT_SUCCESS);
}
