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
	int (*builtin)(char **str_arr);
} builtin_t;

/* ----- FUNCTIONS ----- */

void shell_loop(char *exe);
ssize_t read_line(char *input, size_t *bufsize);
char **split_string(char *input);

int (*check_builtin(char *string))(char **);

char *check_path(char *command);
int exec_cmd(char **str_arr, char *exe, int *cnt);
int interprete_cmd(char **str_arr, char *exe, int *cnt);

/* ----- BUILTINS ----- */
int shell_exit(char **str_arr);
int change_dir(char **str_arr);

void free_str_arr(char **str_arr);

#endif
