#include "monty.h"
/**
 * _strtok - subdivides a line into words
 * @line: pointer to line
 * Return: pointer to words
 */
char **_strtok(char *line)
{
	char **words = NULL;
	char *word = NULL, *line_cpy = NULL, *token = NULL;
	int counter = 0, i;

	if (line == NULL)
		return (NULL);
	line_cpy = strdup(line);
	token = strtok(line_cpy, " ");
	while (token != NULL)
	{
		counter++;
		token = strtok(NULL, " ");
	}
	words = malloc(counter * sizeof(char *));
	if (words == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	word = strtok(line, " ");
	for (i = 0; i < counter; i++)
	{
		words[i] = word;
		word = strtok(NULL, " ");
	}
	return (words);
}
