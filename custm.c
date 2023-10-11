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
		return (atoi(args[1]));
	}
	else
	{
		return (0);
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
		perror("Argument expected to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error in ma_cd.c: changing directory\n");
			return (-1);
		}
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