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

