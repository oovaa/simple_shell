#include "shell.h"

/**
 * eputchar - writes a character to the standard error
 * @c: The character to be written
 *
 * Return: On success, the number of characters written (1).
 * On error, -1 is returned.
 */

int eputchar(char c)
	{
		return (write(2, &c, 1));
	}

/**
 * eputs - writes a string to the standard error
 * @str: The string to be written
 *
 * Return: On success, the number of characters written.
 * On error, -1 is returned.
 */
int eputs(char *str)
{
	int len;

	if (str == NULL)
	{
		write(STDERR_FILENO, "(null)", 6);
		return (6);
	}

	len = _strlen(str);

	if (len > 0)
	{
		return (write(STDERR_FILENO, str, len));
	}
	else
	{
		return (write(STDERR_FILENO, "\n", 1));
	}
}

/**
 * printerr - prints an error message to the standard error
 * @command: The name of the command causing the error
 * @indexno: The index number associated with the error
 *
 * This function prints an error message to the standard error in the format:
 * "<shell_name>: <index>: <command>: not found\n"
 * where shell_name> is the name of the shell (retrieved from the environment),
 * <index> is the provided index number, and <command> is the name of the
 * command causing the error.
 *
 * Return: void
 */

void printerr(char *command, int indexno)
{
	char *index = intostr(indexno);
	char *name = _getenv("_");

	if (command == NULL || command[0] == '\0')
	{
		printerr("Invalid command", 1);
		return;
	}

	if (name != NULL)
	{
		eputs(name);
		eputs(": ");
	}

	if (index != NULL)
	{
		eputs(index);
		eputs(": ");
	}

	eputs(command);
	eputs(": not found\n");

	free(index);
}

/**
 * intostr - Convert an integer to a string.
 *
 * @wai: The integer to be converted.
 *
 * Description:
 * This function takes an integer and converts it to a corresponding
 * string representation. The resulting string is dynamically allocated
 * and should be freed by the caller when no longer needed.
 *
 * Example:
 * int num = 42;
 * char *str_num = intostr(num);
 * // str_num now contains the string "42"
 * free(str_num); // Remember to free the allocated memory.
 *
 * Return: A pointer to the string representation of the integer,
 * or NULL if memory allocation fails.
 */
char *intostr(int wai)
{
	char buffy[50];
	int v = 0;

	if (wai == 0)
		buffy[v++] = '0';

	else
	{
	while (wai > 0)
	{
		buffy[v++] = (wai % 10) + '0';
		wai /= 10;
	}
	}
	buffy[v] = '\0';
	rev_string(buffy);

	return (_strdup(buffy));
}
