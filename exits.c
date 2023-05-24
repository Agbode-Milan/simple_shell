#include "shell.h"

/**
 **_strncat - strncat is used to concatenate two strings
 *
 *@dest: @dest is the first string in this case
 *@src: @src is the second string in this case
 *@n: @n is the amount of bytes to be maximally used in our case
 *
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - _strchr is used to locate a character in a string
 *@s: is the subject string to be parsed
 *
 *@c: is the subject character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 **_strncpy - is used for coping a subject string
 *
 *@dest: @dest is the destination string to be copied to in our caase
 *@src: @src is the source string in this case
 *@n: @n is the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
