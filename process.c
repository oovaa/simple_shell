#include "shell.h"

/**
 * proc - create a new process
 * @args:   arguments
 *
 * Return: 1 (success). Otherwise 0.
 */
int proc(char **args)
{
	pid_t pid;
	int status;

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
 * @result: The array to be populated
 * @count: The number of substrings
 */

void populate_substrings(char *str, char sep, char **result, int count)
{
	int len = _strlen(str);
	int i = 0;
	int substring_index = 0;
	int start = 0;
	size_t substr_len = i - start;


	(void)count;
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
		result[substring_index] = (char *)malloc(i - substr_len);
		if (result[substring_index] == NULL)
		{
			printerr("malloc", 1);
			free_strarr(result);
			exit(EXIT_FAILURE);
		}
		_strncpy(result[substring_index], str + start, i - start);

		substring_index++;
	}
	result[substring_index] = NULL;
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
	char **result;

	count_substrings(str, sep, &count);

	 result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
	{
		printerr("malloc", 1);
		free_strarr(result);
		exit(EXIT_FAILURE);
	}

	populate_substrings(str, sep, result, count);

	return (result);
}
