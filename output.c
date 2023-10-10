#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - prints a string, followed by a new line, to stdout.
 *@str: the string
 */
void _puts(char *str)
{
int i;
i = 0;
while (str[i])
_putchar(str[i++]);

}


/**
 * print_array -  prints n elements of an array
 * of integers, followed by a new line.
 *@a: int array
 *@n: number of elements of the array to be printed
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		if (i != (n - 1))
		{
			_putchar(a[i]);
			_putchar(' ');
		}
		else
			_putchar(a[i]);
	}
	_putchar('\n');
}

/**
 * _strcspn - function that gets the last index of acceptet char
 * @str: string to process
 * @regect: regected char
 * Return: last index of acceptet char
*/

int _strcspn(char *str, char regect)
{
	int i;

	i = 0;

	while (str[i] != regect)
		i++;

	return (i);
}
