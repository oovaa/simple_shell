#include "shell.h"

/**
 * _strlen - check the code
 * @s: the targeted string
 * Return: Always 0.
 */
int _strlen(char *s)
{

int i = 0;

if (s == NULL)
	return 0;

while (*(s + i) != '\0')
{
i++;
}

return (i);
}


/**
 * _atoi - function that convert a string to an integer.
 *@s: targeted string
 * Return: the converted integer value
 */
int _atoi(char *s)
{
int sign = 1;
unsigned int num = 0;

do {
if (s[0] == '-')
	sign *= -1;
else if (s[0] >= '0' && s[0] <= '9')
	num = (num * 10) + (s[0] - '0');
else if (num > 0)
	break;
} while (*s++);
return (num * sign);
}

/**
 * _strcat -  a function that concatenates two strings.
 * @dest: string that will be at the start
 * @src: string that will be at the end
 * Return: printer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	if (dest == NULL || src == NULL)
	{
		perror("./hsh: 1");
		return (NULL);
	}

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	dest[i + j] = '\0';

	return (dest);
}


/**
 * _strncat -  a function that concatenates two strings.
 * @dest: string that will be at the start
 * @src: string that will be at the end
 * @n: bytes from src; and
 * Return: printer to the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
int i = 0;
int j = 0;

while (dest[i++])
;
i--;
for (j = 0; j < n && src[j] != '\0'; j++)
dest[i++] = src[j];

dest[i] = '\0';

return (dest);
}


/**
 * _strcpy - check the code
 *@dest: targeted string
 *@src: given string
 * Return: Always 0.
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == NULL)
	return _strdup(src);

while (*(src + i) != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';

return (dest);
}
