#include "shell.h"

/**
 * ma_exit - Changes the current directory of the process
 * @args: arguments
 *
 * Return: 0.
*/
int ma_exit(char **args)
{
	if (args[1] != NULL && args[1][0] != '\0')
	{
		exit(_atoi(args[1]));
	}
	else
	{
		exit(0);
	}
}


/*
 * ma_cd - Changes the current directory of the process
 * @args: target
 *
 * Return: 1 (Sucess). Otherwise 0.
*/

int ma_cd(char **args) {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("cd");
        return -1;
    }

    if (args[1] == NULL || args[1][0] == '~') {
        char *home = _getenv("HOME");
		if ((args[0] + 1) != NULL)
			_strcat(home, args[1] + 1);

        if (home == NULL) {
            fprintf(stderr, "cd: No $HOME variable set\n");
            return -1;
        }
        if (chdir(home) != 0) {
            perror("cd");
            return -1;
        }
    } else if (_strcmp(args[1], "-") == 0) {
        char *previous_dir = _getenv("OLDPWD");
        if (previous_dir == NULL) {
            fprintf(stderr, "cd: No previous directory available\n");
            return -1;
        }
        if (chdir(previous_dir) != 0) {
            perror("cd");
            return -1;
        }
        printf("%s\n", previous_dir);

        if (_strcmp(previous_dir, cwd) != 0 && _setenv("OLDPWD", cwd, 1) != 0) {
            perror("cd");
            return -1;
        }
        return 0; 
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd");
            return -1;
        }
    }

    // Update the environment variable PWD
    char new_cwd[1024];
    if (getcwd(new_cwd, sizeof(new_cwd)) == NULL) {
        perror("cd");
        return -1;
    }
    if (_setenv("PWD", new_cwd, 1) != 0) {
        perror("cd");
        return -1;
    }

    // Update the environment variable OLDPWD
    if (_strcmp(new_cwd, cwd) != 0 && _setenv("OLDPWD", cwd, 1) != 0) {
        perror("cd");
        return -1;
    }

    return 0;
}


int ma_env(char **args)
{
	int i = 0;
	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
	return 0;
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