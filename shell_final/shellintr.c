#include "shell.h"

int interactive(mesg_t *msg)
{
    return (isatty(STDIN_FILENO) && msg->file_descriptor <= 2);
}

int is_delimiter(char c, const char *delim)
{
    while (*delim)
        if (*delim++ == c)
            return (1);
    return (0);
}

int custom_is_alpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

int custom_atoi_str(const char *s)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0;  s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;
        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return output;
}
