#include "shell.h"

/**
 * *read_line - reads input
 * Return: 0
 */

char *read_line(void)
{
	char *line = NULL;
	int readed_str;
	size_t n = 0;


	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	readed_str = getline(&line, &n, stdin);

	if (readed_str == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
