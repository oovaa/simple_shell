#include "shell.h"

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

	// Count the number of substrings
	while (i < len)
	{
		// Skip leading separators
		while (i < len && str[i] == sep)
			i++;

		if (i == len)
		{
			// If we reached the end of the string, break
			break;
		}

		// Move to the end of the current segment
		while (i < len && str[i] != sep)
			i++;

		// Count the start of a new segment
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

	i = 0;
	// Populate the array with substrings
	while (i < len)
	{
		// Skip leading separators
		while (i < len && str[i] == sep)
			i++;
		if (i == len)
			break;
		// Find the end of the current segment
		int start = i;
		while (i < len && str[i] != sep)
			i++;
		// Allocate memory for the substring
		result[substring_index] = (char *)malloc(i - start + 1);
		if (result[substring_index] == NULL)
		{
			printerr("malloc", 1);
			exit(EXIT_FAILURE);
		}
		// Copy the substring into the array
		_strncpy(result[substring_index], str + start, i - start);

		// Move to the next substring
		substring_index++;
	}
	// Set the last pointer to NULL
	result[substring_index] = NULL;
}

/**
 * strtoarr - Converts a string to an array of strings using a specified delimiter.
 * @str: The target string
 * @sep: The delimiter that separates array elements in the string
 * Return: The array of strings or NULL if malloc fails
 */

char **strtoarr(char *str, char sep)
{
	int count = 0;

	// Count the number of substrings
	count_substrings(str, sep, &count);

	// Allocate an array to contain the substrings
	char **result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
	{
		printerr("malloc", 1);
		exit(EXIT_FAILURE);
	}

	// Populate the array with substrings
	populate_substrings(str, sep, result, count);

	return (result);
}

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

	if (access(str, F_OK) == 0)
	return (str);

	tok = strtoarr(path, ':');
	for (i = 0; tok[i]; i++)
	{
		com = malloc(_strlen(tok[i]) + _strlen(str) + 2);
		if (com == NULL)
		{
			printerr("malloc", 1);
			free(tok);  // Free the previously allocated memory // Updated: Added memory deallocation
			return (NULL);
		}
		_strcpy(com, tok[i]);
		_strcat(com, "/");
		_strcat(com, str);
		com[_strlen(com)] = '\0';

		if (access(com, F_OK) == 0)
		{
			free(tok);  // Free the memory for tok before returning // Updated: Added memory deallocation
			return (com);
		}
		free(com);  // Free the memory for com for this iteration
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
	int i = _strlen(str) - 1;

	while (i >= 0 && str[i] == ' ')
		i--;

	// If the string consists only of spaces
	if (i < 0)
	{
		str[0] = '\0';
	} else
	{
		// Place null terminator at the right position
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

	// Find the '#' character
	while (str[i] && str[i] != '#')
	{
		i++;
	}

	// If no '#' character found, return the original string
	if (str[i] == '\0')
	{
		return (str);
	}

	// Set null terminator at the '#' character
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

	str[_strcspn(str, '\n')] = '\0';

	if (str == NULL)
		return (NULL);

	cleaned_str = handle_hash(str);

	while (*cleaned_str == ' ')
		cleaned_str++;

	cleaned_str = clean_end(cleaned_str);

	return (cleaned_str);
}
