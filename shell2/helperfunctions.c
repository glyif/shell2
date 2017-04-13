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
char *_strdup(char *str)
{
	char *str2;
	int i;
	int length;

	if (str == NULL)
	{
		return (NULL);
	}
	length = _strlen(str);
	str2 = malloc(length + 1 * sizeof(char));
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
char *path_cat(char *dest, char *src)
{
	int i, j, destlen;

	destlen = _strlen(dest);
	i = destlen;
	j = 0;
	dest[i] = '/';
	i++;

	while(src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return(dest);
}
