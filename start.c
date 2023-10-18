#include "shell.h"

/**
 * main - Entry point for the program.
 *
 * Description:
 * This is the main function that serves as the entry point for the program.
 * It receives command-line arguments and performs the necessary operations
 * based on the program's functionality. The number of arguments and the
 * arguments themselves are provided through the parameters 'argc' and 'argv.'
 *
 * Usage:
 *  ./program_name argument1 argument2
 *
 * Return: The exit status of the program.
 */

int main(void)
{
	char *command = NULL;
	char **tokcom = NULL;
	int re = 0;

	while (1)
	{
		command = read_line();
		if (command == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (re);
		}

		command = clean(command);
		replace_variables(command, re);

		if (command == NULL || command[0] == '\0')
			continue;
		tokcom = strtoarr(command, ' ');

		if (!tokcom)
			continue;
		command = look_in_path(tokcom[0]);
		re = exe(command, tokcom);

		if (re != 0)
			if (tokcom[0] != NULL)
				printerr(tokcom[0], 1);
	free(command);
	command = NULL;
	free_strarr(tokcom);
	}
	return (re);
}
