#include "shell.h"
#include <stdarg.h>

int eputchar(char c)
{
	return	(write(2, &c, 1));
}

int eputs(char *str) {
    return write(2, str, _strlen(str));
}

int fulerr(char *com, int status)
{
    char *sh = _getenv("mash"); 
    eputs(sh);
    perror(": 1: ");
    eputs(com);

    // Return an appropriate exit code
    return status;
}



/* int main(void) {
    // Test eputs
    eputs("This is an error message using eputs.\n");

    // Test eputchar
    eputchar('E');
    eputchar('r');
    eputchar('r');
    eputchar('\n');

    return 0;
} */