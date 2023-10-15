#include "shell.h"

/**
 * main - where execution will start
 * Return: 0 success
 *
 */

int main(int argc, char **argv) {
	if (argc > 1) {
		// Non-interactive mode
		return non_interactive_mode(argc, argv);
	} else if (argc == 1) {
		return interactive_mode();
	}
}
