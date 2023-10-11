#include "shell.h"


func check_built_ins(char *ch)
{
    int i;
    
	built_ins spc[] = {
	    {"cd", &ma_cd},
	    {"exit", &ma_exit},
	    {NULL, NULL}
	};

    for (i = 0; spc[i].name != NULL; i++) {
        if (_strcmp(spc[i].name, ch) == 0) {
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

    arr[0] = com;


    id = fork();

    if (id == 0)
    {
        execve(com, arr, environ);
        perror("exec: not excuted");
        return (2);
    }
    else
    {
        wait(NULL);
        return (0);
    }    
}


/* int main(int argc, char const *argv[])
{
    char *arr[] = {"exit", "34", NULL};
    char *com = "exit";
    int re = exe(com, arr);
    return re;
} */