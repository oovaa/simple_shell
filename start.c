#include "shell.h"

/**
 * main - where execution will start
 * Return: 0 success
 *
*/

/* int main(void)
{
	char *comand = NULL;
	char **tokcom = NULL;
	size_t line = 0;

	_puts("$ ");
	getline(&comand, &line, stdin);
	comand[_strcspn(comand, '\n')] = '\0';

	tokcom = strtoarr(comand, ' ');

	printf("%s\n", tokcom[0]);
	comand = look_in_path(tokcom[0]); 



	return (0);
}
 */