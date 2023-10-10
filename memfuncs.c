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

