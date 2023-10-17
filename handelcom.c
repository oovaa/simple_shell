#include "shell.h"

/**
 * look_in_path - returns the path
 * @str: command to look for
 * Return: valid path as string or null
 *
*/

char *look_in_path(char *str)
{
	char *path = gpath(), **tok = NULL, *com = NULL;
	int i = 0;
	int j = 0;

	if (access(str, F_OK) == 0)
	return (str);

	tok = strtoarr(path, ':');
	    if (tok == NULL)
        return NULL;

	for (i = 0; tok[i]; i++)
	{
		com = malloc(_strlen(tok[i]) + _strlen(str) + 2);
		if (com == NULL)
		{
			printerr("malloc", 1);
			free_strarr(tok);
			return (NULL);
		}
		_strcpy(com, tok[i]);
		_strcat(com, "/");
		_strcat(com, str);

		if (access(com, F_OK) == 0)
		{
			free(tok);
			return (com);
		}
		free(com);
	}
	free(tok);
	return (NULL);
}

/**
 * clean_end - Removes trailing spaces from a string.
 * @str: The input string
 * Return: Pointer to the cleaned string
 */

char *clean_end(char *str)
{
	if (str == NULL)
		return "\0";
	
	int i = _strlen(str) - 1;

	while (i >= 0 && str[i] == ' ')
		i--;

	if (i < 0)
	{
		str[0] = '\0';
	} else
	{
		str[i + 1] = '\0';
	}

	return (str);
}

/**
 * handle_hash - Removes comments from a string by setting null
 * terminator at the '#' character.
 * @str: The input string
 * Return: Pointer to the modified string
 */

char *handle_hash(char *str)
{
	int i = 0;

	while (str[i] && str[i] != '#')
	{
		i++;
	}

	if (str[i] == '\0')
	{
		return (str);
	}

	str[i] = '\0';

	return (str);
}

/**
 * clean - Cleans a string by removing leading and
 * trailing spaces and comments.
 * @str: The input string
 * Return: Pointer to the cleaned string
 */

char *clean(char *str)
{
	char *cleaned_str = NULL;

	if (str == NULL)
		return (NULL);

	append_text_to_file("history.txt", str);
	
	str[_strcspn(str, '\n')] = '\0';

	cleaned_str = handle_hash(str);

	while (*cleaned_str == ' ')
		cleaned_str++;

	cleaned_str = clean_end(cleaned_str);

	return (cleaned_str);
}
