#include "shell.h"

typedef int (*func)(char **args);

func check_built_ins(char *ch)
{
	built_ins spc[] = {
	    {"cd", &ma_cd},
	    {"exit", &ma_exit},
	    {NULL, NULL}
	};

    for (int i = 0; spc[i].name != NULL; i++) {
        if (_strcmp(spc[i].name, ch) == 0) {
            return (spc[i].f);
        }
    }

    return (NULL);
}
