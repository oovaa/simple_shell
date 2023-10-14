#include "shell.h"

/**
 * main - where execution will start
 * Return: 0 success
 *
*/




int main(int argc, char **argv)
{
	char *comand = NULL;
	char **tokcom = NULL;
	size_t line = 0;
	int i;
	int re = 0;

	(void)i;
	(void)argc;
	_setenv("mash", argv[0], 1);

	while (1)
	{
		_puts("$ ");
		getline(&comand, &line, stdin);

		append_text_to_file("history.txt", comand);

		comand[_strcspn(comand, '\n')] = '\0';

        replace_variables(comand, re);

		comand = clean(comand);
	
		if (comand[0] == '\0')
			continue;

		tokcom = strtoarr(comand, ' ');

		char *path_command = look_in_path(tokcom[0]);
		
		re = exe(path_command, tokcom);

	}
	return (re);
}
