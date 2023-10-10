#include "shell.h"

/**
 * main - where execution will start
 * Return: 0 success
 *
*/

int main(void)
{
	char *comand = NULL;
	char **tokcom = NULL;
	size_t line = 0;

	_puts("$:");
	getline(&comand, &line, stdin);
	tokcom = strtoarr(comand, ' ');


	return (0);
}
