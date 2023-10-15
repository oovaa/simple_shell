#include "shell.h"

int non_interactive_mode(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [arg1 arg2 ...]\n", argv[0]);
        return 1;
    }

    char **tokcom;
    char *path_command;

    if (argc == 2) {
        // If the command is passed directly in argv[1]
        tokcom = strtoarr(argv[1], ' ');
        path_command = look_in_path(tokcom[0]);
    } else {
        // If the command is already parsed in argv
        tokcom = argv + 1;
        path_command = look_in_path(tokcom[0]);
    }

    if (path_command == NULL) {
        fprintf(stderr, "Error: Command not found in PATH\n");
        if (argc == 2) {
            free(tokcom);
        }
        return 1;
    }

    int re = exe(path_command, tokcom);

    if (argc == 2) {
        free(tokcom);
    }

    free(path_command);

    return re;
}




int interactive_mode() {
    char *command = NULL; 
    char **tokcom = NULL; 
    size_t line = 0; 
    int re = 0; 

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

        char *path_command = look_in_path(tokcom[0]); 

        re = exe(path_command, tokcom); 
    } 

    return re; 
}


