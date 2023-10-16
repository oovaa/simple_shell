#include "shell.h"

/**
 * _setenv - sets an env var
 * @name: the var name
 * @value: the var value
 * @overwrite: 1 to overwrite if exsisted 0 for not
 * Return: 0 sucsess
*/


int _setenv(char *name, char *value, int overwrite)
{
	if (name == NULL || value == NULL) {
        printerr("_setenv", 1);
		return -1;
	}

	char *fullvar = malloc(_strlen(name) + _strlen(value) + 2);
	if (fullvar == NULL) {
		perror("malloc");
		return -1; // or handle the error in an appropriate way
	}

	_strcpy(fullvar, name);
	_strcat(fullvar, "=");
	_strcat(fullvar, value);

	int i;
	int count = 0;

	while (environ[count] != NULL) {
		count++;
	}

	for (i = 0; environ[i]; i++) {
		if (_strncmp(name, environ[i], _strlen(name)) == 0 && overwrite == 1) {
			free(environ[i]);
			environ[i] = _strdup(fullvar); // Assuming you have _strdup implemented
			free(fullvar); // Freeing fullvar since it's no longer needed
			return 0;
		} else if (_strncmp(name, environ[i], _strlen(name)) == 0 && overwrite == 0) {
			free(fullvar); // Freeing fullvar since it's not needed
			return 0;
		}
	}

	char **newenv = malloc((count + 2) * sizeof(char *));
	if (newenv == NULL) {
		printerr("malloc", 1);
		free(fullvar); // Freeing fullvar since it's not needed
		return -1; // or handle the error in an appropriate way
	}

	for (i = 0; i < count; i++) {
		newenv[i] = environ[i];
	}

	newenv[i] = fullvar;
	newenv[i + 1] = NULL; // Ensure the new environment array is null-terminated

	environ = newenv;
	return 0;
}

/**
 * _unsetenv - sets an env var
 * @name: the var name
 * Return: 0 sucsess
*/

int _unsetenv(char *name)
{
	int i, last = 0;

	while (environ[last + 1])
		last++;

	for (i = 0; environ[i]; i++) {
		if (_strncmp(name, environ[i], _strlen(name)) == 0) {
			free(environ[i]);
			environ[i] = environ[last];
			environ[last] = NULL;
			return 0; // success
		}
	}

	return -1; // Return an error if the variable is not found
}

/**
 * gpath - returns the path;
 * Return: path var as string
*/

char *gpath()
{
	char *path = NULL;
	int len = _strlen("PATH");
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], "PATH", len) == 0)
		{
			path = environ[i] + 5;
			break;
		}
	}
	return (path);
}
/**
 * _getenv - returns the env var value;
 * @name: name of the var
 * Return: value or null
*/

char *_getenv(char *name)
{
	int i;
	int len;

	if (name == NULL || *name == '\0') {
        printerr("_getenv", 1);
		return NULL;
	}

	len = _strlen(name);

	if (environ == NULL) {
        printerr("_getenv", 1);
		return NULL;
	}

	for (i = 0; environ[i]; i++) {
		if (environ[i][len] == '=' && _strncmp(name, environ[i], len) == 0) {
			return (environ[i] + len + 1);
		}
	}
    printerr("_getenv", 1);
	return NULL;
}

/* 

int main(void) {
    char *name = "OMA";
    char *value = "test_value1";

    // Test 1: Set environment variable
    printf("Test 1: Set environment variable\n");
    if (_setenv(name, value, 1) == 0) {
        printf("Environment variable set successfully!\n");
    } else {
        perror("Failed to set environment variable\n");
    }

    // Check the value using _getenv
    char *result = _getenv(name);
    if (result != NULL) {
        printf("Value retrieved using _getenv: %s\n", result);
    } else {
        perror("Failed to retrieve value using _getenv\n");
    }

    // Test 2: Set environment variable with overwrite=0 (should not overwrite)
    printf("\nTest 2: Set environment variable with overwrite=0\n");
    if (_setenv(name, "new_value2", 1) == 0) {
        printf("Environment variable set successfully!\n");
    } else {
        perror("Failed to set environment variable\n");
    }

    // Check the value using _getenv
    result = _getenv(name);
    if (result != NULL) {
        printf("Value retrieved using _getenv: %s\n", result);
    } else {
        perror("Failed to retrieve value using _getenv\n");
    }

    // Test 3: Set environment variable with invalid arguments
    printf("\nTest 3: Set environment variable with invalid arguments\n");
    if (_setenv(NULL, value, 1) == 0) {
        printf("Environment variable set successfully!\n");
    } else {
        perror("Failed to set environment variable");
    }

    // Check the value using _getenv
    result = _getenv(name);
    if (result != NULL) {
        printf("Value retrieved using _getenv: %s\n", result);
    } else {
        perror("Failed to retrieve value using _getenv\n");
    }

    return 0;
}
 */

/* 
int main() {
	// Test case 1: _setenv
	printf("Test case 1: _setenv\n");
	_setenv("MY_VAR", "123", 1); // Set environment variable "MY_VAR" to "123"
	char *value1 = _getenv("MY_VAR");
	printf("Value of MY_VAR: %s\n", value1);

	// Test case 2: _unsetenv
	printf("\nTest case 2: _unsetenv\n");
	_unsetenv("MY_VAR"); // Unset environment variable "MY_VAR"
	char *value2 = _getenv("MY_VAR");
	if (value2 == NULL) {
		printf("MY_VAR is unset\n");
	} else {
		printf("Value of MY_VAR: %s\n", value2);
	}

	// Test case 3: _getenv
	printf("\nTest case 3: _getenv\n");
	char *value3 = _getenv("PATH"); // Get the value of the environment variable "PATH"
	printf("Value of PATH: %s\n", value3);

	// Test case 4: Change directory using ma_cd function
	printf("\nTest case 4: ma_cd\n");
	char *args[] = {"cd", "/home/omar/cps", NULL}; // Replace "/path/to/directory" with an actual directory path
	int result = ma_cd(args);
	if (result == 0) {
		printf("Directory changed successfully\n");
		char cwd[1024];
		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			printf("Current directory: %s\n", cwd);
		} else {
			perror("getcwd");
		}
	} else {
		printf("Failed to change directory\n");
	}

	return 0;
}
 */