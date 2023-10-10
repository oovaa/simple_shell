#include "shell.h"

/**
 * strtoarr - from str to array
 * @str: the targeted strinf
 * @del: what separate every array element in str
 * Return: the array of strings or null;
*/

char **strtoarr(char *str, char del)
{
char **arr;
int itmes = 0, i, j, k;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == del)
			itmes++;
	}

	if (itmes == 0)
		{
			arr = malloc(sizeof (char *) );
			arr[0] = str;
			return (arr);
		}
		

if (str == NULL)
	return (NULL);

arr = malloc(sizeof(char *) * (itmes + 2));
if (arr == NULL)
	return (NULL);

i = 0;
j = 0;
for (k = 0; str[k]; k++)
{
	if (str[k] == del)
	{
		arr[i] = malloc(sizeof(char) * (k - j + 1));
		if (arr[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(arr[k]);
			free(arr);
			return (NULL);
		}
		_strncat(arr[i], &str[j], k - j);
		j = k + 1;
		i++;
	}
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


	tok = strtoarr(path, ':');
	for (i = 0; tok[i]; i++)
	{
		com = malloc(_strlen(tok[i]));
		_strcpy(com, tok[i]);
		_strcat(com, "/");
		_strcat(com, str);
		if (open(com, O_RDONLY) != -1)
			return (com);
	}

	return (NULL);
}

