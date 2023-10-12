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
            return (NULL);
        }

		_strcpy(com, tok[i]);
		_strcat(com, "/");
		_strcat(com, str);
		com[_strlen(com)] = '\0';

		if (access(com, F_OK) == 0)
			return (com);
	}

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
	_strncpy(ans, str, i);
	ans[i] = '\0';
	

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
	_strncpy(ans, str, i);

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

/* int main(int argc, char const *argv[])
{
	char *n = "  omar   # abdo     ";
	int i = 0;
	n = clean(n);

	_puts(n);
	
	return (0);
} */

