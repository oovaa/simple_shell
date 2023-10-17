#include "shell.h"


/**
 * _strncpy - function that copies a string.
 * @dest: string that will be at the start
 * @src: string that will be at the end
 * @n: bytes from src;
 * Return: printer to the concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
int i = 0;

    if (dest == NULL)
    {
        dest = (char *)malloc(n);
        if (dest == NULL)
        {
            printerr("Memory allocation failed", EXIT_FAILURE);
            exit(EXIT_FAILURE);
        }
    }

for (i = 0; i < n && src[i] != '\0'; i++)
dest[i] = src[i];

dest[i] = '\0';

return (dest);
}


/**
 * _strcmp - a function that compares two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if strings are the same 1 if not
*/

int _strcmp(char *s1, char *s2)
{

	if (s1 == NULL || s2 == NULL)
	{
		return -1;
	}

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
	}

	return ((int)(*s1 - *s2));
}


/**
 * _strspn - function that gets the length of a prefix substring.
 * @s: targeted string
 * @accept: string to compare
 * Return: length of a prefix substring.
 *
*/

unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int i = 0, j = 0, test = 0;

while (s[i])
{
test = 0;
j = 0;
while (accept[j])
{
if (s[i] == accept[j])
{
count++;
test = 1;
break;
}
j++;
}

if (test == 0)
return (count);

i++;
}
return (count);
}


/**
 * _strpbrk - function that searches a string for any of a set of bytes.
 * @s: targeted string
 * @accept: characters that are accepted
 * Return: pointer to the byte in s that matches one
 * of the bytes in accept, or NULL if no such byte is found
*/

char *_strpbrk(char *s, char *accept)
{
int i = 0;

while (*s)
{
i = 0;
while (accept[i])
{
if (*s == accept[i])
{
return (s);
}
i++;
}
s++;
}
return (NULL);
}


/**
 * _strstr - function that locates a substring.
 * @haystack:the string to search in
 * @needle:the substring to search for
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 *
*/

char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;

	while (haystack[i])
	{
		while (needle[j] && (haystack[i] == needle[0]))
		{
			if (haystack[i + j] == needle[j])
				j++;
			else
				break;
		}
		if (needle[j])
		{
			i++;
			j = 0;
		}
		else
			return (haystack + i);
	}
	return (0);
}

