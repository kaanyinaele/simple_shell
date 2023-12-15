#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function declarations */
void display_prompt(void);
void execute_command(char *command);
int main(void);

/**
 * display_prompt - Displays the shell prompt.
 * This function prints the shell prompt "Basic_Shell$ " to stdout.
 */
void display_prompt(void)
{
	printf("Basic_Shell$ ");
	fflush(stdout);
}

/**
 * execute_command - Executes a command in the shell.
 * @command: The command to be executed
 *
 * This function forks a child process to execute
 * the given command using execlp.
 */
void execute_command(char *command)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execlp(command, command, NULL) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("shell");
	}
	else
	{
		/* Parent process */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * main - The main function of the shell program.
 *
 * This function runs the shell by repeatedly displaying the prompt,
 * reading user input, executing commands,
 * and handling 'exit' to terminate the shell.
 *
 * Return: Always returns 0 on successful completion.
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;

	while (1)
	{
		display_prompt();

		if (getline(&input, &input_size, stdin) == -1)
		{
			printf("\n");
			free(input);
			exit(EXIT_SUCCESS);
		}

		input[strcspn(input, "\n")] = '\0';

		/* Check if the input is "exit" */
		if (strcmp(input, "exit") == 0)
		{
			/* Exit the loop and terminate the program */
			free(input);
			break;
		}

		char *token = strtok(input, " ");

		while (token != NULL)
		{
			execute_command(token);
			token = strtok(NULL, " ");
		}

		free(input);
		input = NULL;
	}

	return (0);
}
