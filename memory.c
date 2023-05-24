#include "shell.h"

/**
 * bfree - bfree will free a pointer and NULLs the address
 *
 * @ptr: this is the address of the pointer to free
 *
 * Return: it will return 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
