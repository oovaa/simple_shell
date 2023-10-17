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
	size_t line = 0;
	int re = 0;
	char *path_command = NULL;

	while (1)
	{
		_puts("$ ");
		if (getline(&command, &line, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(command);
			free(path_command);
			return (re);
		}

		command = clean(command);
		replace_variables(command, re);

		if (command[0] == '\0')
			continue;

		tokcom = strtoarr(command, ' ');
		
		if (tokcom[0])
		path_command = look_in_path(tokcom[0]);
		re = exe(path_command, tokcom);

		if (re != 0)
			if (tokcom[0] != NULL)			
				printerr(tokcom[0], 1);

	}
	if (command != NULL)
		free(command);
	free(path_command);
	free_strarr(tokcom);
	return (re);
}
