#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "main.h"

/**
 * free5 - free up to three strings and two arrays
 * @s1: string 1
 * @s2: string 2
 * @s3: string 3
 * @ar1: array 1
 * @ar2: array 2
 *
 * Return: void
 * Note: the function recieves the address of
 * the pointers it must free
 */

void free5(char **s1, char **s2, char **s3, char ***ar1, char ***ar2)
{
	if (s1)
	{
		if (*s1)
			free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		if (*s2)
			free(*s2);
		*s2 = NULL;
	}
	if (s3)
	{
		if (*s3)
			free(*s3);
		*s3 = NULL;
	}
	if (ar1)
	{
		if (*ar1)
			free(*ar1);
		*ar1 = NULL;
	}
	if (ar2)
	{
		if (*ar2)
			free(*ar2);
		*ar2 = NULL;
	}

}


/**
 * parse_str - parse a str into an array that execve understands
 * @s: string recieved by getline
 * @delim: str of delimiters
 * Return: NULL terminated array on success
 */

char **parse_str(char *s, char *delim)
{
	int i, count_delim;
	char **ar, *tmp;

	if (!s && !delim)
		return (NULL);

	for (i = 0, count_delim = 0; s[i]; i++)
	{
		if (in(s[i], delim) == 1 && (s[i + 1] > 32 && s[i + 1] < 127))
			count_delim++;
	}

	ar = malloc(sizeof(char *) * (count_delim + 3));
	if (!ar)
		return (NULL);
	ar[0] = strtok(s, delim);

	for (tmp = strtok(NULL, delim), i = 1; tmp; tmp = strtok(NULL, delim))
		ar[i++] = tmp;

	ar[i] = NULL;
	return (ar);
}


/**
 * in - checks if a char is in a str
 * @c: char
 * @s: string
 *
 * Return: 1 for true, 0 for false
 */

int in(char c, char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (c == s[i])
			return (1);
	return (0);
}

/**
 * sighandler - function used to handle Ctrl + C
 * @sig: signal
 *
 * Return: void
 */
void sighandler(__attribute__ ((unused)) int sig)
{
	write(STDOUT_FILENO, &"\n$ ", 3);
}
