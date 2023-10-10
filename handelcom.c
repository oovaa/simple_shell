#include "shell.h"

/**
 * strtoarr - from str to array
 * @str: the targeted strinf
 * @del: what separate every array element in str
 * Return: the array of strings or null;
*/

char **strtoarr(char *str, char del)
{
  int i = 0, j = 0;
  char **arr;
  int count;
  int singlestrlen = 0;


  /* str[_strcspn(str, '\n')] = '\0'; */
  count = countchinstr(str, del) + 1;

  arr = malloc(sizeof(char *) * count);

  if (arr == NULL) {
    perror("the array is not allocated");
    return (NULL);
  }

  arr[i] = malloc(sizeof(char) * singlestrlen);


     printf("%d\n", count);
	singlestrlen = _strcspn(arr[j], ' ');


  for (i = 0; str[i]; i++) {

    if (arr[j] == NULL) {
      perror("the string is not allocated");
      return (NULL);
    }

    if (str[i] == del) {
      ++j;
      ++i;
      arr[j] = malloc(sizeof(char) * 100);
    }

    _strncat(arr[j], &str[i], 1);
  }

  for (i = 0; arr[i]; i++) {
    printf("%s\n", arr[i]);
    free(arr[i]);
  }
  
  printf("%d\n", j);

  return (arr);
}

int main(void)
{
    char **arr = strtoarr("omar tata nana", ' ');
    (void)arr;
    return 0;
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

