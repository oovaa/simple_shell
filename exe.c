#include "shell.h"

/**
 * bin_setenv - Implements the setenv built-in command
 * @args: Array of command arguments
 * @com: Array of command arguments
 *
 * Return: 0 on success, -1 on failure
 */
int bin_setenv(char *com, char **args)
{
	char *name;
	char *value;
	int overwrite;

	(void)com;
	if (args[1] == NULL || args[2] == NULL)
	{
		perror(
			"setenv: Too few arguments. Usage: setenv VARIABLE VALUE [override]");
		return (-1);
	}

	name = args[1];
	value = args[2];
	overwrite = (args[3] != NULL) ? _atoi(args[3]) : 1;

	if (_setenv(name, value, overwrite) != 0)
	{
		perror("setenv: Unable to set environment variable");
		return (-1);
	}

	return (0);
}

/**
 * bin_unsetenv - Implements the unsetenv built-in command
 * @args: Array of command arguments
 * @com: ....
 *
 * Return: 0 on success, 1 on failure
 */

int bin_unsetenv(char *com, char **args)
{
	char *name = NULL;

	(void)com;
	if (args[1] == NULL)
		return (1);

	name = args[1];

	if (_unsetenv(name) != 0)
		return (1);


	return (0);
}

/**
 * check_built_ins - Checks if a command is a built-in and returns its function
 * @ch: Command to check
 *
 * Return: Function pointer to the built-in command, or NULL if not a built-in
 */

func check_built_ins(char *ch)
{
	int i = 0;

	built_ins spc[] = {
		{"cd", &ma_cd},
		{"env", &ma_env},
		{"exit", &ma_exit},
		{"setenv", &bin_setenv},
		{"unsetenv", &bin_unsetenv},
		{NULL, NULL}};

	for (i = 0; spc[i].name != NULL; i++)
	{
		if (_strcmp(spc[i].name, ch) == 0)
		{
			return (spc[i].f);
		}
	}

	return (NULL);
}

/**
 * exebi - Executes a built-in command
 * @f: Function pointer to the built-in command
 * @arr: Array of command arguments
 * @com: Array
 *
 * Return: Result of the built-in command execution
 */

int exebi(func f, char *com, char **arr)
{
	int re = 0;

	re = f(com, arr);
	return (re);
}

/**
 * exe - Executes a command
 * @com: Command to execute
 * @arr: Array of command arguments
 * Return: 0 on success, 127 if command not found
 */

int exe(char *com, char **arr)
{
	func f = NULL;

	f = check_built_ins(arr[0]);
	if (f != NULL)
		return (exebi(f, com, arr));

	if (com != NULL)
		if (access((com), F_OK) != 0)
			return (127);

	proc(arr);
	return (0);
}
