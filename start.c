#include "shell.h"

/**
 * main - where execution will start
 * Return: 0 success
 *
 */


int main(int argc, char **argv) {
	char *command = NULL;
	char **tokcom = NULL;
	size_t line = 0;
	int re = 0;
	char *path_command;

	while (1) {
		_puts("$ ");
		if (getline(&command, &line, stdin) == -1) {
			// Handle end-of-file (CTRL+D) in non-interactive mode
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(command);
			free(path_command);  
			return re;
		}

		append_text_to_file("history.txt", command);
		command = clean(command);
		replace_variables(command, re);

		if (command[0] == '\0')
			continue;

		tokcom = strtoarr(command, ' ');

		path_command = look_in_path(tokcom[0]);

		re = exe(path_command, tokcom);

		if (re != 0)
		{
			printerr(tokcom[0], 1);  // Assuming index 1 for simplicity
		}
    }
    if (command != NULL) 
        free(command);
	free_strarr(tokcom);
	return re;
}
