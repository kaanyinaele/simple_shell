#ifndef SHELL_H
#define SHELL_H

/* Include necessary libraries */
#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

/* Function prototypes */
void display_prompt(void);
void execute_command(char *command);
void read_input(char **input, size_t *input_size);
void process_input(char *input);

#endif /* SHELL_H */
