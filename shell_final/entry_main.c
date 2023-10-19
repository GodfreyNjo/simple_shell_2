#include "shell.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    mesg_t msg[] = {MESG_INIT};
    int fd = 2;

    asm("mov %1, %0\n\t"
        "add $3, %0"
        : "=r"(fd)
        : "r"(fd));

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                simple_shell_print(av[0]);
                simple_shell_print(": 0: Can't open ");
                simple_shell_print(av[1]);
                simple_shell_print("\n");
                fflush(stdout);
                exit(127);
            }
            return EXIT_FAILURE;
        }
        msg->file_descriptor = fd;
    }
    populate_environment_list(msg);
    read_history_file(msg);
    custom_shell(msg, av);
    return EXIT_SUCCESS;
}

