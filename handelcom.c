#include "shell.h"

/**
 * strtoarr - from str to array
 * @str: the targeted strinf
 * @del: what separate every array element in str
 * Return: the array of strings or null;
*/
char **strtoarr(char *str, char sep) {
    int len = _strlen(str);
    int c = 0;
    int *count = &c;
    int i = 0;

    // Count the number of substrings
    while (i < len) {
        // Skip leading separators
        while (i < len && str[i] == sep)
            i++;

        if (i == len) {
            // If we reached the end of the string, break
            break;
        }

        // Move to the end of the current segment
        while (i < len && str[i] != sep)
            i++;

        // Count the start of a new segment
        (*count)++;
    }

    // Allocate an array to contain the substrings
    char **result = (char **)malloc(sizeof(char *) * (*count + 1));
    if (result == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // Reset count for substring indexing
    *count = 0;
    i = 0;

    // Populate the array with substrings
    while (i < len) {
        // Skip leading separators
        while (i < len && str[i] == sep)
            i++;

        if (i == len) {
            // If we reached the end of the string, break
            break;
        }

        // Find the end of the current segment
        int start = i;
        while (i < len && str[i] != sep)
            i++;

        // Allocate memory for the substring
        result[*count] = (char *)malloc(i - start + 1);
        if (result[*count] == NULL) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }

        // Copy the substring into the array
        _strncpy(result[*count], str + start, i - start);

        // Move to the next substring
        (*count)++;
    }

    // Set the last pointer to NULL
    result[*count] = NULL;

    return result;
}


/**
 * look_in_path - returns the path
 * @str: command to look for
 * Return: valid path as string or null
 *
*/

char *look_in_path(char *str)
{
	char *path = gpath(), **tok, *com;
	int i;

	if (access(str, F_OK) == 0)
	return (str);


	tok = strtoarr(path, ':');
	for (i = 0; tok[i]; i++)
	{
		com = malloc(_strlen(tok[i]) + _strlen(str) + 2);
		if (com == NULL)
		{
			perror("malloc failed");
			free(tok);  // Free the previously allocated memory // Updated: Added memory deallocation
			return (NULL);
		}

		_strcpy(com, tok[i]);
		_strcat(com, "/");
		_strcat(com, str);
		com[_strlen(com)] = '\0';

		if (access(com, F_OK) == 0) {
            free(tok);  // Free the memory for tok before returning // Updated: Added memory deallocation
            return (com);
        }
        free(com);  // Free the memory for com for this iteration
    }
	free(tok);
	return (NULL);
}

char *clean_end(char *str)
{
	int i;
	char *ans;

	i = _strlen(str) - 1;
	while (i >= 0 && str[i] == ' ')
		i--;
	i += 1;

	ans = malloc(sizeof(char) * (i + 1));
	if (ans != NULL) {
		_strncpy(ans, str, i);
		ans[i] = '\0';
	} else {
		perror("Memory allocation failed in clean_end()");
		return (NULL);
	}
return ans;
}

char *handle_hash(char *str)
{
    char *ans;
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '#')
        {
            break;
        }
        i++;
    }

    // If no '#' character found, use the length of the entire string
    if (i == _strlen(str)) {
		return (str);
    }

    ans = malloc(sizeof(char) * (i + 1));
    if (ans != NULL) {
        _strncpy(ans, str, i);
    } else {
        perror("Memory allocation failed in handle_hash()");
        return (NULL);
    }
    return (ans);
}



char *clean(char *str)
{

	if (str == NULL)
		return NULL;

	str = handle_hash(str);
	
	while (*str == ' ')
		str++;
		
	str = clean_end(str);

	return (str);
}

