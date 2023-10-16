#include "shell.h"
#include <stdarg.h>

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
		return (write(STDERR_FILENO, str, _strlen(str)));
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

		eputs(name);
		eputs(": ");
		eputs(index);
		eputs(": ");
		eputs(command);
		eputs(": not found\n");

		free(index);
	}

/*
 * intostr - function to change integer to string
 * @wai: variable
 * Return: NULL
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
