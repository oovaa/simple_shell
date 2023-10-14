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
    int i = _strlen(str) - 1;

    while (i >= 0 && str[i] == ' ')
        i--;

    // If the string consists only of spaces
    if (i < 0) {
        str[0] = '\0';
    } else {
        // Place null terminator at the right position
        str[i + 1] = '\0';
    }

    return str;
}

char *handle_hash(char *str) {
    int i = 0;

    // Find the '#' character
    while (str[i] && str[i] != '#') {
        i++;
    }

    // If no '#' character found, return the original string
    if (str[i] == '\0') {
        return str;
    }

    // Set null terminator at the '#' character
    str[i] = '\0';

    return str;
}


char *clean(char *str)
{
    char *cleaned_str;
    if (str == NULL)
        return NULL;

    cleaned_str = handle_hash(str);

    while (*cleaned_str == ' ')
        cleaned_str++;

    cleaned_str = clean_end(cleaned_str);

    return cleaned_str;
}


/* 
void pspace(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == ' ')
            putchar('>');
        else
            putchar(str[i]);
        
        i++;
    }
 putchar('\n');   
}

int main(void)
{
    char str1[] = "   Hello   ";
    char str2[] = "   Spaces     ";
    char str3[] = "NoSpaces";
    char str4[] = "   ";
    char str5[] = "";

    printf("Cleaned:  %s>\n", clean_end(str1));
    pspace(str1);

    printf("Cleaned:  %s>\n", clean_end(str2));
    pspace(str2);

    printf("Cleaned:  %s>\n", clean_end(str3));
    pspace(str3);

    printf("Cleaned:  %s>\n", clean_end(str4));
    pspace(str4);

    printf("Cleaned:  %s>\n", clean_end(str5));
    pspace(str5);


    return 0;
}
 */