#include "shell.h"
#include <unistd.h>
#include <string.h>

/**
 * simple_shell_print - Prints a string to the standard output.
 * @input: The string to be printed.
 */
void simple_shell_print(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}

