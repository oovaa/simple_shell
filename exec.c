#include "shell.h"

/**
 * bin_setenv - Implements the setenv built-in command
 * @args: Array of command arguments
 *
 * Return: 0 on success, -1 on failure
 */
int bin_setenv(char **args) {
	if (args[1] == NULL || args[2] == NULL) {
		perror(
			"setenv: Too few arguments. Usage: setenv VARIABLE VALUE [override]");
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

/**
 * bin_unsetenv - Implements the unsetenv built-in command
 * @args: Array of command arguments
 *
 * Return: 0 on success, 1 on failure
 */

int bin_unsetenv(char **args) {
	if (args[1] == NULL) {
		return 1;
	}

	char *name = args[1];

	if (_unsetenv(name) != 0) {
		return 1;
	}

	return 0;
}

/**
 * check_built_ins - Checks if a command is a built-in and returns its function
 * @ch: Command to check
 *
 * Return: Function pointer to the built-in command, or NULL if not a built-in
 */

func check_built_ins(char *ch) {
	int i;

	built_ins spc[] = {
		{"cd", &ma_cd},
		{"env", &ma_env},
		{"exit", &ma_exit},
		{"setenv", &bin_setenv},
		{"unsetenv", &bin_unsetenv},
		{NULL, NULL}};

	for (i = 0; spc[i].name != NULL; i++) {
		if (_strcmp(spc[i].name, ch) == 0) {
			return (spc[i].f);
		}
	}

	return (NULL);
}

/**
 * exebi - Executes a built-in command
 * @f: Function pointer to the built-in command
 * @arr: Array of command arguments
 *
 * Return: Result of the built-in command execution
 */

int exebi(func f, char **arr) {
	int re;

	re = f(arr);
	return (re);
}

/**
 * exe - Executes a command
 * @com: Command to execute
 * @arr: Array of command arguments
 *
 * Return: 0 on success, 127 if command not found
 */

int exe(char *com, char **arr) {
	int id;
	func f;

	f = check_built_ins(arr[0]);
	if (f != NULL)
		return exebi(f, arr);
		
	if (access(com, F_OK) != 0)
		return 127; 
		
	proc(arr);
	return 0;
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
