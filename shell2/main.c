#include "shell2.h"
/**
 * main - function to for the shell
 * Return: integer
 */
int main(void)
{
	extern char **environ;
	char *line = NULL;
	int status;
	size_t linelen = 0;
	size_t len_line;
	pid_t pid;
	char **tok_args;

	while(1)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		len_line = getline(&line, &linelen, stdin);
		line[len_line - 1] = '\0';
		tok_args = tokenizer(line);
		findpath(tok_args);
		pid = fork();
		if (pid < 0)
			perror("Fork did not work");
		else if (pid == 0)
		{
			execve(tok_args[0], tok_args, environ);
			perror("Error in main after execve");
		}
		else
			pid = wait(&status);
	}
/**free len_line/getline stuff, please - not sure how to do this**/
	free((void *)len_line);
}
