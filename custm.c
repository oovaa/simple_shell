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


int is_empty_or_whitespace(const char *str) {
    while (*str) {
        if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r') {
            return 0; // Not empty or whitespace
        }
        str++;
    }
    return 1; // Empty or whitespace
}

/*
 * ma_cd - Changes the current directory of the process
 * @args: target
 *
 * Return: 1 (Sucess). Otherwise 0.
*/

// Assume _getenv, _setenv, _strcmp are implemented elsewhere in your code
int ma_cd(char **args) {
    char *target_dir = args[1];

    if (target_dir == NULL || is_empty_or_whitespace(target_dir)) {
        // No argument provided, change to home directory
        target_dir = _getenv("HOME");
        if (target_dir == NULL) {
            perror("./hsh: 1");
            return 1;
        }
    } else if (_strcmp(target_dir, "-") == 0) {
        // Change to the previous directory
        target_dir = getenv("OLDPWD");
        if (target_dir == NULL) {
            perror("./hsh: 1");
            return 1;
        }
    }

    if (chdir(target_dir) != 0) {
        perror("./hsh: 1");
        return 1;
    }

    return 0;
}


int ma_env(char **args) {
    int i = 0;
    while (environ[i]) {
        if (_puts(environ[i]) == -1 || _putchar('\n') == -1) {
            perror("puts/putchar");
            return -1;
        }
        i++;
    }
    return 0;
}

void _int_to_str(int num, char *str) {
    int i = 0, sign = 0;

    if (num < 0) {
        sign = 1;
        num = -num;
    }

    do {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);

    if (sign) {
        str[i++] = '-';
    }

    str[i] = '\0';
    rev_string(str);
}

/* 
int main() {
    char *cd_args_empty[] = {"cd", "-", NULL};
    char *cd_args_home[] = {"cd", NULL};
    char *cd_args_whitespace[] = {"cd", "   ", NULL};
    char *env_args[] = {"env", NULL};
    char *exit_args[] = {"exit", "42", NULL};

    // Test ma_cd with empty string
    printf("Testing ma_cd with empty string:\n");
    if (ma_cd(cd_args_empty) == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd");
            return 1;
        }
        printf("ma_cd succeeded! Current directory: %s\n", cwd);
    } else {
        fprintf(stderr, "ma_cd failed!\n");
    }

    // Test ma_cd without arguments (should default to home directory)
    printf("\nTesting ma_cd without arguments (default to home directory):\n");
    if (ma_cd(cd_args_home) == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd");
            return 1;
        }
        printf("ma_cd succeeded! Current directory: %s\n", cwd);
    } else {
        fprintf(stderr, "ma_cd failed!\n");
    }

    // Test ma_cd with whitespace string (should default to home directory)
    printf("\nTesting ma_cd with whitespace string (default to home directory):\n");
    if (ma_cd(cd_args_whitespace) == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd");
            return 1;
        }
        printf("ma_cd succeeded! Current directory: %s\n", cwd);
    } else {
        fprintf(stderr, "ma_cd failed!\n");
    }

    // Test ma_env
    // printf("\nTesting ma_env:\n");
    // if (ma_env(env_args) == 0) {
    //     printf("ma_env succeeded!\n");
    // } else {
    //     fprintf(stderr, "ma_env failed!\n");
    // }

    // Test ma_exit
    printf("\nTesting ma_exit:\n");
    ma_exit(exit_args);  // Note: This will exit the program

    return 0;
}
 */