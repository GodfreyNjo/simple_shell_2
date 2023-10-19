#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: mesg_t pointer
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(mesg_t *info, char **buf, size_t *len)
{
    ssize_t r = 0;
    size_t len_p = 0;

    if (!*len) /* if nothing left in the buffer, fill it */
    {
        /*bfree((void **)info->cmd_buf);*/
        custom_free(buf);
        *buf = NULL;
        signal(SIGINT, sigint_handler);
#if USE_CUSTOM_GETLINE
        r = custom_getline(info, buf, &len_p);
#else
        r = get_input(info);
#endif
        if (r > 0)
        {
            if ((*buf)[r - 1] == '\n')
            {
                (*buf)[r - 1] = '\0'; /* remove trailing newline */
                r--;
            }
            info->line_count_flag = 1;
            remove_comments(info);
            build_history_list(info, *buf, info->history_counter++);
            /* if (_strchr(*buf, ';')) is this a command chain? */
            {
                *len = r;
                info->cmd_buffer = buf;
            }
        }
    }
    return r;
}

