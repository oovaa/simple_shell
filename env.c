#include "shell.h"


/**
 * _setenv_existing - Update an existing environment variable.
 *
 * @name: Name of the environment variable.
 * @value: Value to set for the environment variable.
 * @fullvar: Concatenated string of name and value.
 * @overwrite: Flag indicating whether to overwrite existing variable.
 *
 * Return: 0 on success, -1 if the variable is not found.
 */

int _setenv_existing(char *name, char *value, char *fullvar, int overwrite)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0 && overwrite == 1)
		{
			free(environ[i]);
			environ[i] = _strdup(fullvar);
			free(fullvar);
			return (0);
		}
		else if (_strncmp(name, environ[i], _strlen(name)) == 0 && overwrite == 0)
		{
			free(fullvar);
			return (0);
		}
	}

	return (-1); // Variable not found
}


/**
 * _setenv_new - Add a new environment variable.
 *
 * @name: Name of the environment variable.
 * @value: Value to set for the environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */

int _setenv_new(char *name, char *value)
{
	int i;
	int count = 0;
	char *fullvar;
	char **newenv;

	if (name == NULL || value == NULL)
	{
		printerr("_setenv", 1);
		return (-1);
	}

	fullvar = malloc(_strlen(name) + _strlen(value) + 2);
	if (fullvar == NULL)
	{
		perror("malloc");
		return (-1);
	}

	_strcpy(fullvar, name);
	_strcat(fullvar, "=");
	_strcat(fullvar, value);

	while (environ[count] != NULL)
		count++;

	newenv = malloc((count + 2) * sizeof(char *));
	if (newenv == NULL)
	{
		printerr("malloc", 1);
		free(fullvar);
		return (-1);
	}

	for (i = 0; i < count; i++)
		newenv[i] = environ[i];

	newenv[i] = fullvar;
	newenv[i + 1] = NULL;
	environ = newenv;
	return (0);
}

/**
 * _setenv - Set the value of an environment variable.
 *
 * @name: Name of the environment variable.
 * @value: Value to set for the environment variable.
 * @overwrite: Flag indicating whether to overwrite existing variable.
 *
 * Return: 0 on success, -1 on failure.
 */
int _setenv(char *name, char *value, int overwrite)
{
	char *fullvar;

	if (_setenv_existing(name, value, fullvar, overwrite) == 0)
		return (0);

	if (_setenv_new(name, value) == (0))
		return (0);

	free(fullvar);
	return (-1);
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

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			free(environ[i]);
			environ[i] = environ[last];
			environ[last] = NULL;
			return (0); // success
		}
	}

	return (-1); // Return an error if the variable is not found
}

/**
 * gpath - returns the path;
 * Return: path var as string
*/

char *gpath()
{
	char *path = NULL;
	int len = _strlen("PATH");
	int i = 0;

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
