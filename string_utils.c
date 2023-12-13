#include "shell.h"

/**
 * _strcmp - compare two strings
 * @first: first string to be compared
 * @second: second string to be compared
 * Return: difference of the two strings
 */
int _strcmp(char *first, char *second)
{
	int i = 0;

	while (first[i] != '\0' && first[i] == second[i])
	i++;

	return (first[i] - second[i]);
}

/**
 * _strcat - concatenates two strings
 * @destination: string to be concatenated to
 * @source: string to concatenate
 * Return: address of the new string
 */
char *_strcat(char *destination, char *source)
{
	int len_dest = _strlen(destination);
	int len_source = _strlen(source);
	char *new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));

	if (new_string == NULL)
	return (NULL);

	for (int i = 0; i < len_dest; i++)
	new_string[i] = destination[i];

	for (int i = 0; i < len_source; i++)
	new_string[len_dest + i] = source[i];

	new_string[len_dest + len_source] = '\0';
	return (new_string);
}

/**
 * _strspn - gets the length of a prefix substring
 * @str1: string to be searched
 * @str2: string to be used
 */
int _strspn(char *str1, char *str2)

	{
	int match = 0;

	for (int i = 0; str1[i] != '\0' && _strchr(str2, str1[i]) != NULL; i++)
	match++;

	return (match);
}

/**
 * _strcspn - computes segment of str1 which consists of characters not in str2
 * @str1: string to be searched
 * @str2: string to be used
 * Return: index at which a char in str1 exists in str2
 */
int _strcspn(char *str1, char *str2)
	{
	int len = 0;

	for (int i = 0; str1[i] != '\0' && _strchr(str2, str1[i]) == NULL; i++)
	len++;

	return (len);
}

/**
 * _strchr - locates a char in a string
 * @s: string to be searched
 * @c: char to be checked
 * Return: pointer to the first occurrence of c in s
 */
char *_strchr(char *s, char c)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
	if (s[i] == c)
	return (s + i);
	}

	return (NULL);
}

