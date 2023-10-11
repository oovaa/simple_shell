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


extern char **environ;
typedef int (*func)(char **args);



/* exec */
int exe(char *com, char **arr);
int exebi(char **arr);
func check_built_ins(char *ch);




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
void _puts(char *str);
int getIdx(char *str, char c);




/* memfuncs */
char *_memcpy(char *dest, char *src, unsigned int n);
char *_memset(char *s, char b, unsigned int n);



/* fileio */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);


/* setunsetenv */
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
char *gpath();
char *_getenv(char *name);

/* custm */
int ma_exit(char **args);
int ma_cd(char **args);


/* handelcom */
char **strtoarr(char *str, char del);
char *look_in_path(char *str);





typedef struct 
{
	char *name;
	int (*f)(char **args);

}built_ins;

#endif
