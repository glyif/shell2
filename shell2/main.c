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
	pid_t pid;
	char **tok_args;

	while(1)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		getline(&line, &linelen, stdin);

		tok_args = tokenizer(line);
		findpath(tok_args);
		pid = fork();
		if (pid < 0)
			perror("Fork did not work");
		else if (pid == 0)
		{
			execve(tok_args[0], tok_args, environ);
			perror("Error");
		}
		else
			pid = wait(&status);
	}
}
