#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: exits with a given exit status (0) if info->arg_values[0] != "exit"
 */
int _myexit(mesg_t *info)
{
    int exitcheck;

    if (info->arg_values[1])  /* If there is an exit argument */
    {
        exitcheck = custom_err_atoi(info->arg_values[1]);
        if (exitcheck == -1)
        {
            info->error_code = 2;
            print_error_message(info, "Illegal number: ");
            simple_shell_print(info->arg_values[1]);
            simple_shell_print("\n");
            return (1);
        }
        info->exec_status = custom_err_atoi(info->arg_values[1]);
        return (-2);
    }
    info->exec_status = -1;
    return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _mycd(mesg_t *info)
{
    const char *s, *dir;
    char buffer[1024];
    int chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        simple_shell_print("TODO: >>getcwd failure emsg here<<\n");
    if (!info->arg_values[1])
    {
        dir = _get_environment_variable(info, "HOME=");
        if (!dir)
            chdir_ret = chdir((dir = _get_environment_variable(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (custom_strcmp(info->arg_values[1], "-") == 0)
    {
        if (!_get_environment_variable(info, "OLDPWD="))
        {
            simple_shell_print(s);
            simple_shell_print("\n");
            return (1);
        }
        simple_shell_print(_get_environment_variable(info, "OLDPWD="));
        simple_shell_print("\n");
        chdir_ret = chdir((dir = _get_environment_variable(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->arg_values[1]);
    if (chdir_ret == -1)
    {
        print_error_message(info, "can't cd to ");
        simple_shell_print(info->arg_values[1]);
        simple_shell_print("\n");
    }
    else
    {
        custom_set_environment_variable(info, "OLDPWD", _get_environment_variable(info, "PWD="));
        custom_set_environment_variable(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhelp(mesg_t *info)
{
    char **arg_array;

    arg_array = info->arg_values;
    simple_shell_print("help call works. Function not yet implemented \n");
    if (0)
        simple_shell_print(*arg_array); /* temp att_unused workaround */
    return (0);
}

