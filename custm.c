#include "shell.h"

/**
 * ma_exit - Changes the current directory of the process
 * @args: arguments
 *
 * Return: 0.
*/
int ma_exit(char **args)
{
	if (args[1] != NULL)
	{
		exit (_atoi(args[1]));
	}
	else
	{
		exit (0);
	}
}


/**
 * ma_cd - Changes the current directory of the process
 * @args: target
 *
 * Return: 1 (Sucess). Otherwise 0.
*/
int ma_cd(char **args)
{
	if (args[1] == NULL)
	{
		char *home;

		home = getenv("HOME");
		chdir(home);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			char *comand = getenv("_");
			_puts(comand);
			perror(": 1: cd: can't cd to asas");
			return (-1);
		}
	}
	return (0);
}


int ma_env(char **args)
{
	int i;

	i = 0;

	while (environ[i])
	{
		_puts(environ[i++]);
		_putchar('\n');
	}
	return (0);
}


/*
 int main()
{
    char *args[] = {"cd", "/home/omaar/cps", NULL};
    int result = ma_cd(args);

    if (result == 0)
    {
        printf("Directory changed successfully\n");
    }
    else
    {
        printf("Failed to change directory\n");
    }

    return result;
}
 */