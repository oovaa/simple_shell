#include "shell.h"


func check_built_ins(char *ch)
{
	int i;

	built_ins spc[] = {
		{"cd", &ma_cd},
		{"exit", &ma_exit},
		{"env", &ma_env},
		{NULL, NULL}
	};

	for (i = 0; spc[i].name != NULL; i++)
	{
		if (_strcmp(spc[i].name, ch) == 0)
		{
			return (spc[i].f);
		}
	}

	return (NULL);
}


int exebi(func f, char **arr)
{
	int re = f(arr);

	return (re);
}



int exe(char *com, char **arr)
{
	int id;
	func f;

	f = check_built_ins(arr[0]);
	if (f != NULL)
		return (exebi(f, arr));

	printf("%s %s c= %s\n", arr[0], arr[1], com);

    if (access(com, F_OK) != 0)
    {
        perror("command error: No such file or directory");
        return (6);
    }
	
	arr[0] = com;

	id = fork();

	if (id == 0)
	{
		execve(com, arr, environ);
		perror("exe error: No such file or directory\n");
		return (2);
	}
	else
	{
		wait(NULL);
		return (0);
	}
}


/*
 *int main(int argc, char const *argv[])
 *{
 *	char *arr[] =
 *	{"exit", "34", NULL};
 *	char *com = "exit";
 *	int re = exe(com, arr);
 *	return re;
 *}
 */
