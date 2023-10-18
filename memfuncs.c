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
unsigned int i = 0;

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
unsigned int i = 0;

for (i = 0; i < n; i++)
{
s[i] = b;
}
return (s);
}

/**
 * rev_string - reverses a string
 * _putchar - print each character
 * @s: char to check
 *
 * Description: This will reverse a string
 * Return: 0 is success
 */
void rev_string(char *s)
{
	int a = 0, b = 0, c = 0;
	char d  = ' ';

	while (s[a] != '\0')
	{
		a++;
	}
	c = a - 1;
	for (b = 0; c >= 0 && b < c; c--, b++)
	{
		d = s[b];
		s[b] = s[c];
		s[c] = d;
	}
}

/**
 * free_strarr - Frees a dynamically allocated array of strings
 * @arr: The array of strings to be freed
 *
 * This function frees each individual string in the array and then frees
 * the array itself.
 */

void free_strarr(char **arr)
{
	int i;

	if (arr == NULL)
		return;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
	arr = NULL;
}

/**
 * free_strarr_partial - Frees a portion of a string array.
 *
 * @arr: The string array to be partially freed.
 * @count: The number of elements to free from the beginning of the array.
 *
 * Description:
 * This function frees a specified number of elements from the beginning
 * of a string array. It helps in deallocating memory used by a dynamically
 * allocated string array while keeping the remaining elements intact.
 *
 * @arr: The string array to be partially freed.
 * @count: The number of elements to free.
 *
 * Return: None.
 */

void free_strarr_partial(char **arr, int count)
{
	int i;

	if (arr == NULL)
		return;

	for (i = 0; i < count; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
}
