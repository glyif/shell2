#include"shell2.h"
/**
 * _strlen - prints length string in integer
 * @s: string passed to function
 * Return: a
 */
int _strlen(const char *s)
{
	int a = 0;

	while (*(s + a))
		a++;

	return (a);
}
/**
 * _strdup - function returns pointer to new string
 * @str: string that is being passed
 * Return: pointer
 */
char *_strdup(const char *str)
{
	char *str2;
	int i;
	int length;

	if (str == NULL)
	{
		return (NULL);
	}
	length = _strlen(str);
	str2 = malloc(length + 1 * sizeof(const char));
	i = 0;
	while (i < length)
	{
		str2[i] = str[i];
		i++;
	}
	return (str2);
/** do I need to free here?? Why did this pass checker? **/
	free(str2);
}
/**
 *
 *
 *
 */
char *pathcat(char *dest, char *dir, char **tok_args)
{
	unsigned int i, j;

	i = 0;
	j = 0;

	while(dir[i] != '\0')
	{
		dest[i] = dir[i];
		i++;
	}
	i++;
	dir[i] = '/';
	while(tok_args[j] != '\0')
	{
		dest[i] = tok_args[j][0];
		i++;
		j++;
	}
	dest[i] = '\0';
	return(dest);
}
