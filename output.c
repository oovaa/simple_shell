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
 * Return: number of printed bytes.
 */

int _puts(char *str)
{
	int i;

	i = 0;
	while (str[i])
		_putchar(str[i++]);

	return (i);
}

/**
 * getIdx - Returns the index of the first
 *  occurrence of character c in string str.
 * @str: The string to search.
 * @c: The character to find.
 *
 * Return: The index of the first occurrence of c, or -1 if not found.
 */

int getIdx(char *str, char c)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}

	return (-1);
}


/**
 * replace_variables - Replaces special variables in the command string.
 * @command: The command string.
 * @status: The exit status of the last command.
 */

void replace_variables(char *command, int status)
{
	char *ptr;
	char buffer[1024];
	int pid = getpid();

	while ((ptr = _strstr(command, "$$")) != NULL)
	{
		*ptr = '\0';
		_strcpy(buffer, command);
		_int_to_str(pid, buffer + _strlen(buffer));
		_strcat(buffer, ptr + 2);
		_strcpy(command, buffer);
	}

	while ((ptr = _strstr(command, "$?")) != NULL)
	{
		*ptr = '\0';
		_strcpy(buffer, command);
		_int_to_str(status, buffer + _strlen(buffer));
		_strcat(buffer, ptr + 2);
		_strcpy(command, buffer);
	}
}
