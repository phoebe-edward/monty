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
	data->words = NULL;

	helping(args);
	free(data);
	free(args);
	return (EXIT_SUCCESS);
}
