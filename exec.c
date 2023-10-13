#include "shell.h"

// Updated setenv function with override option
int bin_setenv(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        perror("setenv: Too few arguments. Usage: setenv VARIABLE VALUE [override]");
        return -1;
    }

    char *name = args[1];
    char *value = args[2];
    int overwrite = (args[3] != NULL) ? _atoi(args[3]) : 1;

    if (_setenv(name, value, overwrite) != 0) {
        perror("setenv: Unable to set environment variable");
        return -1;
    }

    return 0;
}


int bin_unsetenv(char **args) {
    if (args[1] == NULL) {
        perror("unsetenv: Missing argument. Usage: unsetenv VARIABLE");
        return 1;
    }

    char *name = args[1];

    if (_unsetenv(name) != 0) {
        perror("unsetenv: Unable to unset environment variable");
        return 1;
    }

    return 0;
}


func check_built_ins(char *ch)
{
	int i;

	built_ins spc[] = {
		{"cd", &ma_cd},
		{"env", &ma_env},
		{"exit", &ma_exit},
		{"setenv", &bin_setenv},
		{"unsetenv", &bin_unsetenv},
		{NULL, NULL}
	};

	for (i = 0; spc[i].name != NULL; i++)
	{
		if (_strcmp(spc[i].name, ch) == 0)
		{
			return (spc[i].f);
		}
	}

	return (NULL);
}


int exebi(func f, char **arr)
{
	int re = f(arr);

	return (re);
}



int exe(char *com, char **arr)
{
	int id;
	func f;

	f = check_built_ins(arr[0]);
	if (f != NULL)
		return (exebi(f, arr));

    if (_strcmp(arr[0], "exit") == 0)
    {
        // Call the exit function directly
        ma_exit(arr);
    }

	printf("%s %s c= %s\n", arr[0], arr[1], com);

    if (access(com, F_OK) != 0)
    {
        perror("command error: No such file or directory");
        return (6);
    }
	
	arr[0] = com;

	id = fork();

	if (id == 0)
	{
		execve(com, arr, environ);
		perror("exe error: No such file or directory\n");
		return (2);
	}
	else
	{
		wait(NULL);
		return (0);
	}
}



/* int main(void) {
    char *setenv_args[] = {"setenv", "TEST_VAR", "test_value", NULL};
    char *unsetenv_args[] = {"unsetenv", "TEST_VAR", NULL};
    char *unsetenv_invalid_args[] = {"unsetenv", NULL};
    char *setenv_missing_value_args[] = {"setenv", "TEST_VAR", NULL};
    char *unsetenv_missing_name_args[] = {"unsetenv", NULL};

    printf("Test 1: Set environment variable\n");
    if (bin_setenv(setenv_args) == 0) {
        printf("Environment variable set successfully!\n");
    } else {
        perror(stderr, "Failed to set environment variable\n");
    }

    printf("\nTest 2: Unset environment variable\n");
    if (bin_unsetenv(unsetenv_args) == 0) {
        printf("Environment variable unset successfully!\n");
    } else {
        fprintf(stderr, "Failed to unset environment variable\n");
    }

    printf("\nTest 3: Set environment variable with missing value\n");
    if (bin_setenv(setenv_missing_value_args) == 0) {
        printf("Environment variable set successfully!\n");
    } else {
        fprintf(stderr, "Failed to set environment variable\n");
    }

    printf("\nTest 4: Unset environment variable with missing name\n");
    if (bin_unsetenv(unsetenv_missing_name_args) == 0) {
        printf("Environment variable unset successfully!\n");
    } else {
        fprintf(stderr, "Failed to unset environment variable\n");
    }

    printf("\nTest 5: Set environment variable with missing name\n");
    if (bin_setenv(NULL) == 0) {
        printf("Environment variable set successfully!\n");
    } else {
        fprintf(stderr, "Failed to set environment variable\n");
    }

    printf("\nTest 6: Unset environment variable with missing name\n");
    if (bin_unsetenv(NULL) == 0) {
        printf("Environment variable unset successfully!\n");
    } else {
        fprintf(stderr, "Failed to unset environment variable\n");
    }

    return 0;
}
 */

