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
	int i, j, last = 0;
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

	for (int i = 0; environ[i]; i++)
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
	char *val = NULL;
	int len = _strlen(name);

	for (int i = 0; environ[i]; i++)
	{

		if (_strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			val = environ[i] + len + 1;
			return (val);
		}
	}
return (NULL);
}
