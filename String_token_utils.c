#include "shell.h"

/**
 * tokenizer - tokenizes input and stores it into an array
 * @input_string: input to be parsed
 * @delim: delimiter to be used, needs to be a one-character string
 * Return: array of tokens
 */
char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 * print - prints a string to stdout
 * @string: string to be printed
 * @stream: stream to print out to
 * Return: void, return nothing
 */
void print(char *string, int stream)
{
	for (int i = 0; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}

/**
 * remove_newline - removes newline from a string
 * @str: string to be used
 * Return: void
 */
void remove_newline(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
}

/**
 * _strcpy - copies a string to another buffer
 * @source: source to copy from
 * @dest: destination to copy to
 * Return: void
 */
void _strcpy(char *source, char *dest)
{
	for (int i = 0; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[_strlen(dest)] = '\0';
}

/**
 * _strlen - counts string length
 * @string: string to be counted
 * Return: length of the string
 */
int _strlen(char *string)
{
	if (string == NULL)
		return (0);

	int len;

	for (len = 0; string[len] != '\0'; len++)
		;
	return (len);
}
