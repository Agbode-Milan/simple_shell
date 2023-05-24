#include "shell.h"

/**
 * _myenv - we use env to print the current environment.
 * @info: This is the structure that has in it potential arguments.
 *          It is used to constant function prototype.
 * Return: Return is always 0.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - geytenv will get us the value of an environ variable
 * @info: This is the structure that has in it potential arguments.
 *          It is used to constant function prototype.
 * @name: env var name
 *
 * Return: Return is always 0.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 *
 * @info: This is the structure that has in it potential arguments.
 *        It is used to constant function prototype.
 *
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - The unsetenv removes any environment variable
 *
 * @info: This is the structure that has in it potential arguments.
 *        It is used to constant function prototype.
 *
 *  Return: returns 0 upon success.
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - Here populate_env_list populates env linked list
 *
 * @info: This is the structure that has in it potential arguments.
 *          It is used to constant function prototype.
 *
 * Return: will always 0 if successful.
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
