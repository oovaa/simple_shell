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
	int i;

	_puts("$ ");
	getline(&comand, &line, stdin);
	comand[_strcspn(comand, '\n')] = '\0';

	tokcom = strtoarr(comand, ' ');


	comand = malloc(sizeof(char) * _strlen(tokcom[0] + 1));

	comand = look_in_path(tokcom[0]);

	if (comand == NULL)
	{
		_puts(tokcom[0]);
		perror(": 1: qwerty: not found");
		return 1;
	}
	 
    exe(comand, tokcom);



	return (0);
} 
