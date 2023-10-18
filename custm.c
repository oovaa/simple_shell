#include "shell.h"

/**
 * ma_exit - Changes the current directory of the process
 * @args: arguments
 * @com: ...
 *
 * Return: 0.
*/
int ma_exit(char *com, char **args)
{
	int i;
	char invaexit[] = "exit: Illegal number: ";
	char *path = _getenv("_");

	free(com);
	if (args[1] != NULL && args[1][0] != '\0')
	{
		i = _atoi(args[1]);
		if (i < 0)
		{
			eputs(path);
			eputs(": ");
			eputs("1: ");
			eputs(invaexit);
			eputs(args[1]);
			eputs("\n");
			free_strarr(args);
			exit(EXIT_FAILURE);
		}

		free_strarr(args);
		exit(i);
	}
	else
	{
		free_strarr(args);
		free(com);
		exit(0);
	}
}

/**
 * is_empty_or_whitespace - Checks if a string is empty
 * or consists only of whitespace characters.
 * @str: The input string to be checked.
 *
 * Return: 1 if the string is empty or consists only of
 * whitespace characters, 0 otherwise.
 *
 * Description:
 * This function examines a string and determines if it
 *  is empty (i.e., a NULL pointer or an
 * empty string) or if it consists only of whitespace
 * characters (spaces, tabs, and newline).
 * Returns 1 if the string is empty or consists only of
 * whitespace characters, and 0 otherwise.
 */

int is_empty_or_whitespace(const char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
 * ma_cd - Changes the current directory of the process
 * @args: target
 * @com: unused
 * Return: 0 (Sucess). Otherwise 1.
*/

int ma_cd(char *com, char **args)
{
	char *new_dir = args[1];

	(void)com;

	if (new_dir == NULL || *new_dir == '\0')
	{
		new_dir = _getenv("HOME");

		if (new_dir == NULL)
		{
			printerr("cd", 1);
			return (1);
		}
	}

	if (chdir(new_dir) != 0)
	{
		printerr("cd", 1);
		return (1);
	}

	return (0);
}

/**
 * ma_env - Implements the built-in command 'env'.
 * @args: Array of command arguments.
 * @com: com
 *
 * Return: 0 on success, -1 on failure.
 *
 * Description:
 * This function is the implementation of the 'env' built-in command.
 * It prints the current environment variables to the standard output.
 *
 * Usage:
 *  ma_env(args);
 *
 * Return Value:
 *  Returns 0 on success and -1 on failure.
 */

int ma_env(char *com, char **args)
{
	int i = 0;

(void)args;
(void)com;

	while (environ[i])
	{
		if (_puts(environ[i]) == -1 || _putchar('\n') == -1)
		{
			printerr("ma_env", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

/**
 * _int_to_str - Converts an integer to a string.
 * @num: The integer to convert.
 * @str: A buffer to store the resulting string.
 *
 * Description:
 * This function converts an integer to its string representation and stores
 * it in the provided buffer. It also handles negative numbers and uses the
 * helper function 'rev_string' to reverse the resulting string.
 *
 * Usage:
 *  _int_to_str(42, buffer);
 *
 * @num: The integer to be converted.
 * @str: A buffer to store the resulting string.
 */

void _int_to_str(int num, char *str)
{
	int i = 0, sign = 0;

	if (num < 0)
	{
		sign = 1;
		num = -num;
	}

	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (sign)
	{
		str[i++] = '-';
	}

	str[i] = '\0';
	rev_string(str);
}
