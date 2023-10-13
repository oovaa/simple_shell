#include "shell.h"

/**
 * strtoarr - from str to array
 * @str: the targeted strinf
 * @del: what separate every array element in str
 * Return: the array of strings or null;
*/

char **strtoarr(char *str, char del)
{
	int i = 0;
	char **arr, *tok = NULL;
	int count, singlestrlen = 0;


	/* str[_strcspn(str, '\n')] = '\0'; */
	count = countchinstr(str, del) + 1;

	arr = malloc(sizeof(char *) * (count + 1));

	for (i = 0; singlestrlen != -1 ; i++)
	{
	 singlestrlen = getIdx(str, del);
		 if (singlestrlen != -1)
		 {
			 tok = malloc(sizeof(char) * (singlestrlen + 1));
			 if (tok == NULL) {
				perror("malloc failed");
				free(arr);  // Free the previously allocated memory
				return NULL;
			}

			 _strncpy(tok, str, singlestrlen);
			 str += singlestrlen + 1;
		 }
		 else
		 {
			 tok = _strdup(str);
		 }
			 arr[i] = tok;
	}
			arr[i] = NULL;

	return (arr);
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
 ans = malloc(sizeof(char) * (i + 1));
	if (ans != NULL) {
		_strncpy(ans, str, i);
	} else
	{
		perror("Memory allocation failed in handle_hash()");
		return(NULL);
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

