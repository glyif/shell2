#include "shell2.h"
/**
 * tokenizer - function to tokenize getline
 * @line: pointer to line passed for tokenization
 * Return: pointer to pointer of type char
 */
char **tokenizer(char *line)
{
	char **tok_args;
	char *token;
	size_t i = 0;

	if(line == NULL)
		perror("This is not what we want: ");
	tok_args = malloc(sizeof(char*) * BUFF_SIZE);
	if(tok_args == NULL)
		perror("malloc failed");
	token = strtok(line, " ");
	while(token != NULL)
	{
		tok_args[i] = token;
		token = strtok(NULL, " \n\t\r");
		i++;
	}
	return(tok_args);
}
