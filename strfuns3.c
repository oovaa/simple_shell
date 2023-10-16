#include "shell.h"

/**
 * _strcspn - function that gets the last index of acceptet char
 * @str: string to process
 * @regect: regected char
 * Return: last index of acceptet char
 */

int _strcspn(char *str, char regect) {
	int i;

	i = 0;

	while (str[i] != regect)
		i++;

	return (i);
}

/**
 * _strchr - function that locates a character in a string.
 * @s: the string containing the character
 * @c: the character
 * Return: a pointer to the first occurrence of the character c
 */

char *_strchr(char *s, char c) {
	while (*s) {
		if (*s != c)
			s++;
		else
			return (s);
	}
	if (c == '\0')
		return (s);

	return (NULL);
}

/**
 * _strncmp - a function that compares two strings.
 * @s1: first string
 * @s2: second string
 * @n: number of chars to compare
 *
 * Return: 0 if strings are the same 1 if not
 */

int _strncmp(char *s1, char *s2, int n) {
	int i;

	for (i = 0; i < n; ++i) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == '\0' || s2[i] == '\0')
			break;
	}
	return (0);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the source string
 * Return: returns a pointer to the duplicated string.
 */
char *_strdup(char *str) {
	int len, i;
	char *newstr;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	newstr = malloc(len * sizeof(char) + 1);

	if (newstr == NULL) {
		perror("malloc failed");
		return NULL;
	}

	for (i = 0; str[i]; i++)
		newstr[i] = str[i];

	newstr[i] = '\0';

	return (newstr);
}

/**
 * countchinstr - counts the number the char appeared in a string
 * @str: string to look in
 * @ch: char to look for
 * Return: number the char appeared in a string
 */

int countchinstr(char *str, char ch) {
	int i, n = 0;

	for (i = 0; str[i]; i++) {
		if (str[i] == ch)
			++n;
	}
	return (n);
}
