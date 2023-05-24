#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * _myhistory - Displays the history list, one command per line, preceded
 *              by line numbers starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_alias(info->history);
	return (0);
}

/**
 * unset_alias - Unsets an alias.
 * @info: Parameter struct.
 * @str: The string alias.
 *
 * Return: Always 0 on success, 1 on error.
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret = 0;

	p = strchr(str, '=');
	if (!p)
		return 1;
	c = *p;
	*p = 0;
	delete_node_at_index(&(info->alias), get_node_index(info->alias, str));
	*p = c;
	return ret;
}

/**
 * set_alias - Sets an alias.
 * @info: Parameter struct.
 * @str: The string alias.
 *
 * Return: Always 0 on success, 1 on error.
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = strchr(str, '=');
	if (!p)
		return 1;
	if (!*++p)
		return unset_alias(info, str);

	unset_alias(info, str);
	add_node_end(&(info->alias), str);
	return 0;

}

/**
 * print_alias - Prints an alias string.
 * @node: The alias node.
 *
 * Return: Always 0 on success, 1 on error.
 */
int print_alias(list_t *node)
{
	if (node)
	{
		char *p = strchr(node->str, '=');
		if (p)
		{
			*p = '\0';
			printf("%s='%s'\n", node->str, p + 1);
			*p = '=';
		}
	}
	return (0);
}

/**
 * _myalias - Mimics the alias builtin (man alias).
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Always 0.
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
		{
			list_t *alias_node = node_starts_with(info->alias, info->argv[i], '=');
			if (alias_node != NULL)
				print_alias(alias_node);
		}
	}

	return (0);
}

