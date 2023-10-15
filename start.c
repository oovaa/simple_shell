#include "shell.h"

/**
 * main - where execution will start
 * Return: 0 success
 *
 */

int main(void) {
    char *command = NULL; 
    char **tokcom = NULL; 
    size_t line = 0; 
    int re = 0; 
    char *path_command;
    _setenv("mash", _getenv("SHELL"), 1); 

    while (1) 
    { 
        _puts("$ "); 
        getline(&command, &line, stdin); 

        append_text_to_file("history.txt", command); 

        command[_strcspn(command, '\n')] = '\0'; 

        replace_variables(command, re); 

        command = clean(command); 

        if (command[0] == '\0') 
            continue; 

        tokcom = strtoarr(command, ' '); 

        path_command = look_in_path(tokcom[0]); 

        re = exe(path_command, tokcom); 
    } 
    free(command);
    free(path_command);
    free_strarr(tokcom);
    return re; 
}
