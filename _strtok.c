#include "monty.h"
/**
 * _strtok - subdivides a line into words
 * @line: pointer to line
 * Return: pointer to words
 */
char **_strtok(char *line)
{
	char **words = NULL;
	char *word = NULL;
	int i = 0;

	if (line == NULL)
		return (NULL);
	word = strtok(line, " ");
	while (word != NULL)
	{
		words[i] = word;
		i++;
		word = strtok(NULL, " ");
	}
	return (words);
}
