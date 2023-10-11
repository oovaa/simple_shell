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
       tok = _strdup(str);

       arr[i] = tok;

  }
      arr[i + 1] = NULL;

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
		_strcpy(com, tok[i]);
		_strcat(com, "/");
		_strcat(com, str);
    com[_strlen(com)] = '\0';

		if (access(com, F_OK) == 0)
			return (com);
	}

	return (NULL);
}

