#include "shell.h"

/**
 * _memcpy - function that fills memory with a constant byte.
 * @dest: targeted string
 * @src:string will be copied
 * @n: number of bytes to fill
 * Return: pointer to the mem area
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{

unsigned int i;
for (i = 0; i < n; i++)
{
dest[i] = src[i];
}

return (dest);
}

/**
 * _memset - function that fills memory with a constant byte.
 * @s: the mem area
 * @b:the byte to fill with
 * @n: number of bytes to fill
 * Return: pointer to the mem area
*/

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
{
s[i] = b;
}
return (s);
}


/**
 * _strchr - function that locates a character in a string.
 * @s: the string containing the character
 * @c: the character
 * Return: a pointer to the first occurrence of the character c
*/

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			s++;
		else
			return (s);
	}
	if (c == '\0')
		return (s);

	return (NULL);
}

/**
 * _strncmp - a function that compares two strings.
 * @s1: first string
 * @s2: second string
 * @n: number of chars to compare
 *
 * Return: 0 if strings are the same 1 if not
*/

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == '\0')
			break;
	}
	return (0);

}


/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the source string
 * Return: returns a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
int len, i;
char *newstr;

if (str == NULL)
return (NULL);

len = _strlen(str);
newstr = malloc(len *sizeof(char) + 1);

if (newstr == NULL)
return (NULL);

for (i = 0; str[i] ; i++)
newstr[i] = str[i];

newstr[i] = '\0';


return (newstr);
}

