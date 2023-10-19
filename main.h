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

#define line_size 1024

extern char **environ;

/**
 * struct builtin_t - struct for that holds builtin cmds and their functions
 * @str: builtin command
 * @builtin: associated function
 */

typedef struct builtin_t
{
	char *str;
	void (*builtin)(char **str_arr, char *input, char *exe,
			int *cnt);
} builtin_t;

/**
 * struct alias_t - Represents an alias in a linked list.
 * @name: The name of the alias.
 * @value: The value associated with the alias.
 * @next: A pointer to the next alias in the linked list.
 *
 * Description: This structure defines a node in a linked list of aliases.
 * Each node contains an alias name, its associated value, and a pointer
 * to the next alias in the list. This allows for the creation of a
 * dynamic list of aliases, where each node represents a unique alias
 * along with its corresponding value.
 */
typedef struct alias_t
{
	char *name;
	char *value;
	struct alias_t *next;
} alias;

/* Global pointer to the head of the linked list */
#ifdef DEFINE_ALIAS
alias *head = NULL;
#else
extern alias *head;
#endif

/* exit status external variable */
#ifdef EXIT_STATUS
int exit_status = 0;
#else
extern int exit_status;
#endif

/* ----- MAIN FUNCTIONS ----- */

void shell_loop(char *exe, char *file);
ssize_t read_line(char **input, ssize_t *bufsize, FILE *stream);

int parse_string(char *input, char *exe, int *cnt);
int interprete_cmd(char *input, char *exe, int *cnt, char *str);
int exec_cmd(char **str_arr, char *exe, int *cnt);
char *check_path(char *command);
void check_variable(char *input);
char *replace_alias(char *str_arr);


/* ----- BUILTINS ----- */
void (*check_builtin(char *string))(char **, char *, char *, int *);
void shell_exit(char **str_arr, char *input, char *exe, int *cnt);
void shell_setenv(char **str_arr, char *input, char *exe, int *cnt);
void shell_unsetenv(char **str_arr, char *input, char *exe, int *cnt);
void change_dir(char **str_arr, char *input, char *exe, int *cnt);
void print_env(char **str_arr, char *input, char *exe, int *cnt);
void alias_builtin(char **str_arr, char *input, char *exe, int *cnt);

/* ---- HELPER FUNCTIONS ----- */
char *create_env(char *var, char *value);
void free_str_arr(char **str_arr);
int string_to_int(char *s);
void write_err(char *str);
void perror_exit(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void create_alias(char *name, char *value);
void print_alias(void);
char *search_alias(char *name);
void free_alias(void);
char *_strchr(char *s, char c);
int _strlen(char *s);
char *_strdup(char *str);
char *_strndup(char *str, size_t n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
unsigned int _strcspn(char *s, char *reject);
char *_strsep(char **str, char *delim);
char *_strncpy(char *dest, char *src, int n);
void check_comment(char *str);
char *convert_int_to_str(int n);
char *modify_alias(alias *check, char *name, char *value);
size_t i_arr(size_t *val);
int detectControlOperators(const char *command);
void print_colon_err(char *exe, int *cnt);
int check_ptr(char *ptr, int *cnt, char *exe);
void file_error(char *exe, char *file);

void _print(char *str);
void _print_err(char *str);

#endif
