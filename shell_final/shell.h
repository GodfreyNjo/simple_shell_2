#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define INPUT_BUFFER_SIZE 1024
#define OUTPUT_BUFFER_SIZE 1024
#define FLUSH_BUFFER -1
#define READ_BUFFER_SIZE 1024


#define COMMAND_DEFAULT 0
#define COMMAND_OR_CONDITION 1
#define COMMAND_AND_CONDITION 2
#define COMMAND_CHAINED 3

#define CONVERT_TO_LOWERCASE 1
#define CONVERT_TO_UNSIGNED 2

#define USE_CUSTOM_GETLINE 0
#define USE_CUSTOM_STRTOK 0

#define HISTORY_FILENAME ".custom_shell_history"
#define MAX_HISTORY_ENTRIES 4096

extern char **custom_environment_vars;

typedef struct drp_t
{
    int num;
    char *str;
    struct drp_t *next;
} drp_t;

typedef struct mesg_info
{
    char *args;
    char **arg_values;
    char *cmd_path;
    int arg_count;
    unsigned int line_num;
    int error_code;
    int line_count_flag;
    char *file_name;
    drp_t *env_list;
    drp_t *hist_list;
    drp_t *alias_list;
    char **env_vars;
    int env_modification;
    int exec_status;
    char **cmd_buffer;
    int buffer_type;
    int file_descriptor;
    int history_counter;
} mesg_t;

#define MESG_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
    0, 0, 0}

typedef struct builtin
{
    char *type;
    int (*func)(mesg_t *);
} builtin_table;

int custom_shell(mesg_t *, char **);
int find_builtin_command(mesg_t *);
void find_command(mesg_t *);
void fork_command(mesg_t *);
int custom_shell_loop(char **);
void custom_error_puts(char *);
int custom_error_putchar(char);
int custom_put_fd(char c, int fd);
int custom_puts_fd(const char *str, int fd);
int custom_strlen(const char *);
int custom_strcmp(const char *, const char *);
const char *custom_starts_with(const char *, const char *);
char *custom_strcat(char *, const char *);
char *custom_strcpy(char *, const char *);
char *custom_strdup(const char *);
void custom_puts(const char *);
int custom_putchar(char);
char *custom_strncpy(char *, const char *, int);
char *custom_strncat(char *, const char *, int);
char *custom_strchr(const char *, int);
char **custom_strtok(char *, const char *);
char **custom_strtok2(char *, const char *);
char *custom_memset(char *, char, unsigned int);
void custom_free(char **);
void *custom_realloc(void *, unsigned int, unsigned int);
int custom_free_buffer(void **);
int custom_atoi(const mesg_t *);
int is_delimiter(char, const char *);
int custom_is_alpha(int);
int custom_atoi_str(const char *);
int custom_err_atoi(const char *);
void print_error_message(mesg_t *, const char *);
int print_digit(int, int);
char *convert_to_string(long int, int, int);
void remove_comments(mesg_t *);
int custom_exit(mesg_t *);
int custom_cd(mesg_t *);
int custom_help(mesg_t *);
int custom_history(mesg_t *);
int custom_alias(mesg_t *);
ssize_t get_input(mesg_t *);
int custom_getline(mesg_t *, char **, size_t *);
void sigint_handler(mesg_t *);
void clear_mesg_struct(mesg_t *);
void set_mesg_struct(mesg_t *, char **);
void free_mesg_struct(mesg_t *, int);
const char *_get_environment_variable(mesg_t *, const char *);
int custom_environment(mesg_t *);
int custom_set_environment_variable(mesg_t *, const char *, const char *);
int custom_unset_environment_variable(mesg_t *, const char *);
int populate_environment_list(mesg_t *);
char **get_environment_variables(mesg_t *);
int custom_unset_environment_variable(mesg_t *, const char *);
char *get_history_filename(mesg_t *mesg);
int write_history_file(mesg_t *mesg);
int read_history_file(mesg_t *mesg);
int build_history_list(mesg_t *mesg, char *buffer, int history_count);
int renumber_history(mesg_t *mesg);
drp_t *add_list_node(drp_t **, const char *, int);
drp_t *add_list_node_end(drp_t **, const char *, int);
size_t print_list_of_strings(const drp_t *);
int delete_node_at_index(drp_t **, unsigned int);
void free_list_of_nodes(drp_t **);
size_t list_length(const drp_t *);
char **list_to_string_array(drp_t *);
size_t print_list_of_nodes(const drp_t *);
drp_t *node_starts_with_string(drp_t *, const char *, char);
ssize_t get_node_index(const drp_t *, const drp_t *);
int is_chained(const mesg_t *, const char *, size_t *);
void check_chained(mesg_t *, const char *, size_t *, size_t, size_t);
int replace_aliases(mesg_t *);
int replace_variables(mesg_t *);
int replace_string_buffer(char **, const char *);
void simple_shell_print(const char *input);
int print_dmn(int input, int fd);

#endif

