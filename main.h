#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

extern char **environ;

/**
 * struct builtin_t - struct for that holds builtin cmds and their functions
 * @str: builtin command
 * @builtin: associated function
 */

typedef struct builtin_t
{
	char *str;
	void (*builtin)(char **str_arr, char *input, char *exe, int *cnt);
} builtin_t;

/* ----- MAIN FUNCTIONS ----- */

void shell_loop(char *exe);
ssize_t read_line(char *input, size_t *bufsize);

int parse_string(char *input, char *exe, int *cnt);
int interprete_cmd(char *input, char *exe, int *cnt, char *str);
int exec_cmd(char **str_arr, char *exe, int *cnt);
char *check_path(char *command);
void check_variable(char *input);


/* ----- BUILTINS ----- */
void (*check_builtin(char *string))(char **, char *, char *, int *);
void shell_exit(char **str_arr, char *input, char *exe, int *cnt);
void shell_setenv(char **str_arr, char *input, char *exe, int *cnt);
void shell_unsetenv(char **str_arr, char *input, char *exe, int *cnt);
void change_dir(char **str_arr, char *input, char *exe, int *cnt);

/* ---- HELPER FUNCTIONS ----- */
char *create_env(char *var, char *value);
void free_str_arr(char **str_arr);
int string_to_int(char *s);
void write_err(char *str);
void perror_exit(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strchr(char *s, char c);

#endif
