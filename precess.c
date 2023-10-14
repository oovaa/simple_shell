#include "shell.h"

/**
 * process - create a new process
 * @args:   arguments
 *
 * Return: 1 (success). Otherwise 0.
 */
int proc(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Forking error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}