#include "shell.h"

/**
 * custom_history - displays the history list, one command by line, preceded
 *                with line numbers, starting at 0.
 * @mesg: Structure containing potential arguments.
 * Return: Always 0
 */
int custom_history(mesg_t *mesg)
{
    print_list_of_strings(mesg->hist_list);
    return (0);
}

/**
 * unset_alias - unsets an alias.
 * @mesg: Structure containing potential arguments.
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(mesg_t *mesg, char *str)
{
    char *p, c;
    int ret;

    p = custom_strchr(str, '=');
    if (!p)
        return (1);
    c = *p;
    *p = 0;
    ret = delete_node_at_index(&(mesg->alias_list), get_node_index(mesg->alias_list, node_starts_with_string(mesg->alias_list, str, -1)));
    *p = c;
    return (ret);
}

/**
 * set_alias - sets an alias.
 * @mesg: Structure containing potential arguments.
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(mesg_t *mesg, char *str)
{
    char *p;

    p = custom_strchr(str, '=');
    if (!p)
        return (1);
    if (!*++p)
        return (unset_alias(mesg, str));

    unset_alias(mesg, str);
    return (add_list_node_end(&(mesg->alias_list), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string.
 * @node: the alias node
 *  * Return: Always 0 on success, 1 on error
 */
int print_alias(const drp_t *node)
{
    const char *p = NULL, *a = NULL;

    if (node)
    {
        p = custom_strchr(node->str, '=');
        for (a = node->str; a <= p; a++)
            custom_putchar(*a);
        custom_putchar('\'');
        custom_puts(p + 1);
        custom_puts("'\n");
        return (0);
    }
    return (1);
}

/**
 * custom_alias - mimics the alias builtin (man alias).
 * @mesg: Structure containing potential arguments.
 * Return: Always 0
 */
int custom_alias(mesg_t *mesg)
{
    int i = 0;
    const char *p = NULL;

    drp_t *node = NULL;  if (mesg->arg_count == 1)
    {
        node = mesg->alias_list;
        while (node)
        {
            print_alias(node);
            node = node->next;
        }
        return (0);
    }
    for (i = 1; mesg->arg_values[i]; i++)
    {
        p = custom_strchr(mesg->arg_values[i], '=');
        if (p)
            set_alias(mesg, mesg->arg_values[i]);
        else
            print_alias(node_starts_with_string(mesg->alias_list, mesg->arg_values[i], '='));
    }

    return (0);
}

/**
 * custom_atoi_str - custom atoi for strings.
 * @s: the string to convert to an integer.
 * Return: the integer value.
 */
int custom_atoi_str(const char *s)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (s[0] == '-')
    {
        sign = -1;
        i++;
    }

    for (; s[i] != '\0'; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + (s[i] - '0');
        }
        else
        {
            break;
        }
    }

    return sign * result;
}

