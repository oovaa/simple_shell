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
	char *fullvar = malloc(_strlen(name) + _strlen(value) + 2);
	char **newenv;
	int i;
	int count = 0;

while (environ[count] != NULL)
	count++;

_strcpy(fullvar, name);
_strcat(fullvar, "=");
_strcat(fullvar, value);

for (i = 0; environ[i]; i++)
{
	if (_strncmp(name, environ[i], _strlen(name)) == 0 && overwrite == 1)
	{
		free(environ[i]);
		environ[i] = _strdup(fullvar);
		return (0);
	}
	else if (_strncmp(name, environ[i], _strlen(name)) == 0 && overwrite == 0)
	{
		free(fullvar);
		return (0);
	}
}

newenv = malloc((count + 2) * sizeof(char *));
for (i = 0; i < count; i++)
newenv[i] = environ[i];

newenv[i] = fullvar;

environ = newenv;

return (0);
}

/**
 * _unsetenv - sets an env var
 * @name: the var name
 * Return: 0 sucsess
*/

int _unsetenv(char *name)
{
	int i, last = 0;
	char *tmp;

	while (environ[last + 1])
		last++;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			tmp = environ[i];
			environ[i] = environ[last];
			environ[last] = NULL;
			return (0);
		}
	}
	(void)tmp;
	return (1);
}
/**
 * gpath - returns the path;
 * Return: path as string
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
	char *val = NULL;
	int len = _strlen(name);

	for (i = 0; environ[i]; i++)
	{

		if (_strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			val = environ[i] + len + 1;
			return (val);
		}
	}
return (NULL);
}
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