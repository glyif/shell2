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
	/* need to terminate string with null byte */
	str2[i] = '\0';
	return (str2);
}
/**
 *
 *
 *
 */
char *pathcat(char *dest, char *dir, char **tok_args)
{
	unsigned int i, j ,k;

	i = 0;
	j = 0;
	while(dir[i] != '\0')
	{
		dest[i] = dir[i];
		i++;
	}
	dest[i] = '/';
	i++;
	while(tok_args[j] != '\0')
	{
		k = 0;
		while (tok_args[j][k] != '\0')
		{
			dest[i] = tok_args[j][k];
			i++;
			k++;
		}
		j++;
	}
	dest[i] = '\0';
	return(dest);
}

/**
 * _strcmp - function to compare strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _strcpy - function to copy string to new dest
 * @dest: where the string is being assigned
 * @src: where it is coming from
 * Return: a char
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int length;

	length = _strlen(src);
	for (i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	return ((char *)dest);
}
