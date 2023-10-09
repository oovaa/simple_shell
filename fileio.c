#include "shell.h"



/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 * O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t r, w, o;
char *buf;

if (filename == NULL)
return (0);

buf = malloc(sizeof(char) * letters);

if (buf == NULL)
return (0);

o = open(filename, O_RDONLY);
r = read(o, buf, letters);
w = write(STDOUT_FILENO, buf, r);

if (o == -1 || r == -1 || w == -1 || w != r)
{
free(buf);
return (0);
}

free(buf);
close(o);

return (w);

}


/**
 * create_file -creates an array of chars, and initializes
 *
 * @text_content: is a NULL terminated string to write to the file
 * @filename: is the name of the file to create
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
int o, w, len = 0;


if (filename == NULL)
	return (-1);

if (text_content != NULL)
{
	for (len = 0; text_content[len];)
		len++;
}

o = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

close(o);

return (1);

}


/**
 * append_text_to_file - appends a text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
		len = write(fd, text_content, _strlen(text_content));

	close(fd);

	if (len == -1)
		return (-1);

	return (1);

}
