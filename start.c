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

	if (argc >= 2) {
		// Non-interactive mode
		printf("%s\n", argv[1]);
		tokcom = strtoarr(argv[1], ' ');

		if (tokcom != NULL) {
			path_command = look_in_path(tokcom[0]);
			re = exe(path_command, tokcom);

			// Free allocated memory
			free(path_command);
			free_strarr(tokcom);

			return re;
		} else {
			fprintf(stderr, "Error: Unable to parse command\n");
			return 1;
		}
	}

	while (1) {
		_puts("$ ");
		getline(&command, &line, stdin);

		append_text_to_file("history.txt", command);

		command[_strcspn(command, '\n')] = '\0';

		replace_variables(command, re);

		command = clean(command);

		if (command[0] == '\0')
			continue;

		tokcom = strtoarr(command, ' ');

		path_command = look_in_path(tokcom[0]);

		re = exe(path_command, tokcom);
	}
	free(command);
	free(path_command);
	free_strarr(tokcom);
	return re;
}
