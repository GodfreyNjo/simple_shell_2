#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(mesg_t *info)
{
    const char *env_value;
    int i;

    simple_shell_print("Current Environment:\n");

    env_value = NULL;
    for (i = 0; info->env_vars[i]; i++)
    {
        env_value = _get_environment_variable(info, info->env_vars[i]);
        if (env_value)
        {
            simple_shell_print(info->env_vars[i]);
            simple_shell_print("=");
            simple_shell_print(env_value);
            simple_shell_print("\n");
        }
    }

    return 0;
}

/**
 * _getenv - gets the value of an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @name: env var name
 *
 * Return: the value
 */
const char *_getenv(mesg_t *info, const char *name)
{
    return _get_environment_variable(info, name);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _mysetenv(mesg_t *info)
{
    const char *env_name;
    const char *env_value;

    if (info->arg_count != 3)
    {
        simple_shell_print("Incorrect number of arguments\n");
        return 1;
    }

    env_name = info->arg_values[1];
    env_value = info->arg_values[2];

    if (custom_set_environment_variable(info, env_name, env_value) == 0)
    {
        return 1;
    }

    simple_shell_print("Environment variable set.\n");
    return 0;
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(mesg_t *info)
{
    int i;
    const char *env_name;

    if (info->arg_count == 1)
    {
        simple_shell_print("Too few arguments.\n");
        return 1;
    }

    for (i = 1; i <= info->arg_count; i++)
    {
        env_name = info->arg_values[i];
        custom_unset_environment_variable(info, env_name);
    }

    simple_shell_print("Environment variable(s) unset.\n");
    return 0;
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int populate_env_list(mesg_t *info)
{
    int i;
    const char *env_var;

    info->env_list = NULL;

    for (i = 0; info->env_vars[i]; i++)
    {
        env_var = info->env_vars[i];
        add_list_node_end(&info->env_list, env_var, 0);
    }

    simple_shell_print("Environment list populated.\n");
    return 0;
}

