#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

/* Constants */
#define MAX_INPUT_SIZE 1024
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/* Struct for mapping command names to functions */
typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

/* External Variables */
extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/* Helper Functions */
void print(char *, int);
char **tokenizer(char *, char *);
void remove_newline(char *);
int _strlen(char *);
void _strcpy(char *, char *);

/* More Helper Functions */
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/* Even More Helper Functions */
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int);
void remove_comment(char *);

/* Utility Functions */
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

/* Built-in Functions */
void env(char **);
void quit(char **);

/* Main Functions */
extern void non_interactive(void);
extern void initializer(char **current_command, int type_command);

#endif /* SHELL_H */

