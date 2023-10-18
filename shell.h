#ifndef SHELL_H
#define SHELL_H

/* includes */
#include "unistd.h"
#include "stdlib.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>


extern char **environ;
typedef int (*func)(char **args);

/* process */
int proc(char **args);
void count_substrings(char *str, char sep, int *count);
char **populate_substrings(char *str, char sep, int count);
char **strtoarr(char *str, char sep);


/* err.c */
int eputs(char *str);
int eputchar(char c);
void printerr(char *command, int indexno);
char *intostr(int wai);



/* exec */
int exe(char *com, char **arr);
int exebi(func f, char **arr);
func check_built_ins(char *ch);
int bin_unsetenv(char **args);
int bin_setenv(char **args);




/* string fuctions */
int _atoi(char *s);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
int _strcspn(char *str, char regect);
char *_strchr(char *s, char c);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
int countchinstr(char *str, char ch);


/* output */
int _putchar(char c);
int _puts(char *str);
int getIdx(char *str, char c);
void replace_variables(char *command, int status);


/* memfuncs */
char *_memcpy(char *dest, char *src, unsigned int n);
char *_memset(char *s, char b, unsigned int n);
void rev_string(char *s);
void free_strarr(char **arr);
void free_strarr_partial(char **arr, int count);



/* fileio */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
char *gpath();


/* env */
int _setenv_new(char *name, char *value);
int _setenv(char *name, char *value, int overwrite);
int _setenv_existing(char *name, char *value, char *fullvar, int overwrite);
int _unsetenv(char *name);
char *_getenv(char *name);

/* custm */
int ma_exit(char **args);
int ma_cd(char **args);
int ma_env(char **args);
int is_empty_or_whitespace(const char *str);
void _int_to_str(int num, char *str);


/* handelcom */
char **strtoarr(char *str, char del);
char *look_in_path(char *str);
char *clean(char *str);
char *clean_end(char *str);
char *handle_hash(char *str);

/* ... (other function declarations) */

/**
 * struct built_ins - Represents a built-in command in the shell.
 * @name: The name of the built-in command.
 * @f: Pointer to the function implementing the built-in command.
 *
 * Description:
 * This structure is used to represent a built-in command in the shell.
 * It contains the name of the command and a function pointer to the
 * corresponding implementation.
 */
typedef struct built_ins
{
	char *name;
	int (*f)(char **args);

} built_ins;

#endif
