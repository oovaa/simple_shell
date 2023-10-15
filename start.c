#include "shell.h"

/**
 * main - where execution will start
 * Return: 0 success
 *
 */

int main(int argc, char **argv) {
    if (isatty(STDIN_FILENO))
	{
		return interactive_mode();
	}
	else
	{
		return non_interactive_mode(argc, argv);
	}
}
