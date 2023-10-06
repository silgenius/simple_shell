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

/**
 * struct builtin_t - struct for that holds builtin commands and their functions
 * @str: builtin commnad
 * @builtin: associated function
 */

typedef struct {
	char *str;
	int (*builtin)(char **str_arr);
} builtin_t;

/* ----- FUNCTIONS ----- */

void shell_loop(void);
ssize_t read_line(char *input, size_t *bufsize);
char **split_string(char *input);

int (*check_builtin(char *string))(char **);

char *check_path(char *command);
int exec_cmd(char **str_arr);
int interprete_cmd(char **str_arr);

/* ----- BUILTINS ----- */
int shell_exit(char **str_arr);

#endif
