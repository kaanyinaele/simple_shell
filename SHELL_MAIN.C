int main(int argc __attribute__((unused)), char **argv)
{
	char **current_command = NULL;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	shell_name = argv[0];

	// Check if the shell is running interactively
	if (isatty(STDIN_FILENO))
	{
		// Interactive mode
		while (1)
		{
			interactive_mode();
		}
	}
	else
	{
		// Non-interactive_mode();
		non_interactive_mode();
	}
	return status;
}
void interactive_mode(void)
{
	print(" ($) ", STDOUT_FILENO);

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
void non_interactive_mode(void)
{
	char **current_command = NULL;
	int i;
	size_t n = 0;

	while (getline(&line, &n, stdin) != -1)
	{
		remove_newline(line);
		remove_comment(line);
		commands = tokenizer(line, ";");

		for (i = 0; commands[i] != NULL; i++)
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

	free(line);
	exit(status);
}
