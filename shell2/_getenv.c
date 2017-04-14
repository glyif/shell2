#include"shell2.h"
/**
 * _getenv - returns the colon deliminated varible from evironment
 * @name: name of variable in the environment
 * Return: match
 */
char *_getenv(const char *name)
{
	extern char **environ;
	const char *token;
	char *match;
/**what is a better way to malloc this out **/
	match = malloc(sizeof(char) * 256);
	while (*environ)
	{
		token = strtok(*environ, "=");
		while (token)
		{
			if (strcmp(token, name) == 0)
			{
				token = strtok(NULL, "=");
				strcpy(match, token);
				return (match);
			}
			token = strtok(NULL, "=");
		}
		environ++;
	}
/**need to create appropriate failure response **/
	return ("cant find");
}
