# Simple Shell Project

This is a simple shell implementation in C.

## Overview

This shell project provides a basic command-line interface with support for built-in commands, external commands, and environmental variable management.

## Features

- Built-in commands: exit, cd, env, setenv, unsetenv
- Execution of external commands
- Environmental variable management
- Input/output redirection (to be implemented)
- Pipelines (to be implemented)

## Usage

1. **Compilation:**
   To compile the shell project, use the following command:
   ```bash
   gcc -o shell *.c -Wall -Werror -pedantic -std=gnu89

This command compiles all the source files into an executable named shell.

Run the Shell:

bash
Copy code
./shell
Supported Commands:
```
exit: Exit the shell.
cd [directory]: Change the current directory.
env: Display environment variables.
setenv [variable] [value] [overwrite]: Set an environment variable.
unsetenv [variable]: Unset an environment variable.
```
Example Usage:


$ ./shell
```
Simple Shell$ ls
file1.txt file2.txt
Simple Shell$ cd ..
Simple Shell$ env
PATH=/usr/bin:/bin
HOME=/home/user
Simple Shell$ exit
```

Main Function:

```
#include "shell.h"

int main(void)
{
    char *command = NULL;
    char **tokenized_command = NULL;
    size_t line = 0;
    int return_status = 0;

    while (1)
    {
        _puts("$ ");
        getline(&command, &line, stdin);

        // Append the command to history file
        append_text_to_file("history.txt", command);

        // Remove the newline character
        command[_strcspn(command, '\n')] = '\0';

        // Clean up the command
        command = clean(command);

        // Tokenize the command
        tokenized_command = strtoarr(command, ' ');

        // Look for the command in the system's PATH
        command = look_in_path(tokenized_command[0]);

        // Execute the command
        return_status = exe(command, tokenized_command);
    }

    // Free dynamically allocated memory before exiting
    free(command);
    free(tokenized_command);

    return return_status;
}
```
### Contributing
Feel free to contribute to this project by providing bug reports, suggestions, or additional features.

### License
This project is licensed under the MIT License - see the LICENSE file for details. 
