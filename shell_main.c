#include "shell.h"
#include "utility_function.c"

char *line = NULL;
char **commands = NULL;
char *shell_name;
int status = 0;


int main(int argc __attribute__((unused)), char **argv)
{
	char **current_command = NULL;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	shell_name = argv[0];

/* Check if the shell is running interactively */
if (isatty(STDIN_FILENO))
{
/* Interactive mode */
while (1)
{
	print(" Basic Shell >$ ", STDOUT_FILENO);

			if (getline(&line, &n, stdin) == -1)
			{
				free(line);
				exit(status);
			}

			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");

			for (int i = 0; commands[i] != NULL; i++)
			{
				current_command = tokenizer(commands[i], " ");

				if (current_command[0] == NULL)
				{
					free(current_command);
					break;

				}

				initializer(current_command, parse_command(current_command[0]));
				free(current_command);
				}

			free(commands);
			}
			else
			{
/* Non-interactive mode */
		non_interactive();
		}
	return (status);
}

void interactive_mode(void)
{

}

void non_interactive_mode(void)
{

}

void initializer(char **current_command, int type_command)
{

}

int parse_command(char *command)
{
	return (0);
}


