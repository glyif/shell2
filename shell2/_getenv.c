#include"shell2.h"
char **copy_env(void)
{
	extern char **environ;
	char **_env;
	int i;
	i = 0;
	_env = calloc(sizeof(char *), 50);

	while (environ[i] != NULL)
	{
		_env[i] = malloc(strlen(environ[i]));
		_env[i] = _strcpy(_env[i], environ[i]);
		i++;
	}

	return (_env);
}

/**
 * _getenv - returns the colon deliminated varible from evironment
 * @name: name of variable in the environment
 * Return: match
 */
char *_getenv(const char *name)
{
	char **_env;
	const char *token;
	char *match;

	_env = copy_env();
/**what is a better way to malloc this out **/
	match = malloc(sizeof(char) * 1024);
	while (*_env)
	{
		token = strtok(*_env, "=");
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
		_env++;
	}
	free(match);
/**need to create appropriate failure response **/
	return ("cant find");
}
