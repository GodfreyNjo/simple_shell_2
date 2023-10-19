#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
    simple_shell_print(str);
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
    char str[2];
    str[0] = c;
    str[1] = '\0';
    simple_shell_print(str);
    return 1;
}

/**
 * _putfd - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c)
{
    char str[2];
    str[0] = c;
    str[1] = '\0';
    simple_shell_print(str);
    return 1;
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 *
 * Return: the number of characters put
 */
int _putsfd(char *str)
{
    simple_shell_print(str);
    return custom_strlen(str);
}

