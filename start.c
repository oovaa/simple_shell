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
	int re = 0;
	
	(void)i;
	
while (1)
{
	_puts("$ ");
	getline(&comand, &line, stdin);
	append_text_to_file("history.txt", comand);

	comand[_strcspn(comand, '\n')] = '\0';

	tokcom = strtoarr(comand, ' ');

	comand = _strdup(tokcom[0]);

	comand = look_in_path(tokcom[0]);
	 
    re = exe(comand, tokcom);
}
	return (re);
} 

