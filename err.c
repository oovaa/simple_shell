#include "shell.h"
#include <stdarg.h>


int eputchar(char c) { return (write(2, &c, 1)); }

int eputs(char *str) { return write(STDERR_FILENO, str, _strlen(str)); }

void srn_printerr(char *name, char *vampcmd, int indexno) {
    char *index = intostr(indexno);

    eputs(name);
    eputs(": ");
    eputs(index);
    eputs(": ");
    eputs(vampcmd);
    eputs(": not found\n");

    free(index);
}

/*
 * srn_intostr - function to change integer to string
 * @wai: variable
 * Return: NULL
 */

char *intostr(int wai) {
    char buffy[50];
    int v = 0;

    if (wai == 0)
      buffy[v++] = '0';

    else {
      while (wai > 0) {
          buffy[v++] = (wai % 10) + '0';
          wai /= 10;
      }
    }
    buffy[v] = '\0';
    rev_string(buffy);

    return (_strdup(buffy));
}
