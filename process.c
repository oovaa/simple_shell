#include "shell.h"

/**
 * proc - create a new process
 * @args:   arguments
 *
 * Return: 1 (success). Otherwise 0.
 */
int proc(char **args)
{
	pid_t pid = 0;
	int status = 0;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			printerr("execvp", 1);
		}
		exit(EXIT_FAILURE);
	}
		else if (pid < 0)
	{
			printerr("fork", 1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}

/**
 * count_substrings - Counts the number of substrings in a string.
 * @str: The target string
 * @sep: The delimiter that separates array elements in the string
 * @count: A pointer to the count variable to be updated
 */
void count_substrings(char *str, char sep, int *count)
{
	int len = _strlen(str);
	int i = 0;

	while (i < len)
	{
		while (i < len && str[i] == sep)
			i++;

		if (i == len)
		{
			break;
		}

		while (i < len && str[i] != sep)
			i++;

		(*count)++;
	}
}

/**
 * populate_substrings - Populates an array with substrings from a string.
 * @str: The target string
 * @sep: The delimiter that separates array elements in the string
 * @count: The number of substrings
 * Return: The populated array or NULL in case of an error
 */

char **populate_substrings(char *str, char sep, int count)
{
	int len = _strlen(str);
	int i = 0;
	int substring_index = 0;
	int start;
	char **result = (char **)malloc(sizeof(char *) * (count + 1));

	if (result == NULL)
	{
		printerr("malloc", 1);
		return (NULL);
	}

	i = 0;
	while (i < len)
	{
		while (i < len && str[i] == sep)
			i++;
		if (i == len)
			break;
		start = i;
		while (i < len && str[i] != sep)
			i++;
		result[substring_index] = (char *)malloc(i - start + 1);
		if (result[substring_index] == NULL)
		{
			printerr("malloc", 1);
			free_strarr(result);
			return (NULL);
		}
		_strncpy(result[substring_index], str + start, i - start);
		substring_index++;
	}
	result[substring_index] = NULL;
	return (result);
}

/**
 * strtoarr - Converts a string to an array of
 * strings using a specified delimiter.
 * @str: The target string
 * @sep: The delimiter that separates array elements in the string
 * Return: The array of strings or NULL if malloc fails
 */

char **strtoarr(char *str, char sep)
{
	int count = 0;
	char **result = NULL;

	if (str == NULL)
	{
		printerr("strtoarr", 1);
		return (NULL);
	}

	count_substrings(str, sep, &count);

	result = populate_substrings(str, sep, count);

	if (result == NULL)
		return (NULL);

	return (result);
}
