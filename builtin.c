#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "builtin.h"
#include "types.h"

int _myexit(struct info_t *info);
int _mycd(struct info_t *info);
int _myhelp(struct info_t *info)

	/**
 * _myhelp - Builtin command 'help' to display help information
 * @info: Pointer to the info_t structure containing command information
 *
 * Return: Always returns 0
 */



/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 *
 * Return: The exit status of the program
 */

int main(int argc, char **argv)
{
	struct info_t info;

	info.argc = argc;
	info.argv = argv;

	for (int i = 0; i < info.argc; i++)
	{
		if (strcmp(argv[i], "exit") == 0)
			return (_myexit(&info));
		else if (strcmp(argv[i], "cd") == 0)
			return (_mycd(&info));
		else if (strcmp(argv[i], "help") == 0)
			return (_myhelp(&info));
	}

	printf("Usage: builtin <command>\n");
	return (1);
}

/**
 * _myexit - Builtin command 'exit' to terminate the shell
 * @info: Pointer to the info_t structure containing command information
 *
 * Return: 1 if an illegal number is provided, -2 to indicate exit status
 */
int _myexit(struct info_t *info)
{
	int exitcheck;

	if (info->argc > 1)
	{
		exitcheck = atoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			printf("Illegal number: %s\n", info->argv[1]);
			return (1);
		}
		info->status = exitcheck;
		return (-2);
	}
	info->status = -1;
	return (-2);
}

/**
 * _mycd - Builtin command 'cd' to change the current working directory
 * @info: Pointer to the info_t structure containing command information
 *
 * Return: Always returns 0
 */

int _mycd(struct info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
	{
		printf("TODO: >>getcwd failure emsg here<<\n");
	}
	if (info->argc < 2)
	{
		dir = getenv("HOME");
		if (!dir)
			chdir_ret = chdir("/");
		else
			chdir_ret = chdir(dir);
	}
	else if (strcmp(info->argv[1], "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (!dir)
		{
			printf("%s\n", s);
			return (1);
		}
		chdir_ret = chdir(dir);
	} else
	{
		chdir_ret = chdir(info->argv[1]);
	}
	if (chdir_ret == -1)
		printf("can't cd to %s\n", info->argv[1]);
	else
	{
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", strdup(getcwd(buffer, 1024)), 1);
	}
	return (0);
}

/**
 * _myhelp - Builtin command 'help' to display help information
 * @info: Pointer to the info_t structure containing command information
 *
 * Return: Always returns 0
 */

int _myhelp(struct info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	printf("help call works. Function not yet implemented\n");
	if (0)
		printf("%s\n", *arg_array);
	return (0);
}

