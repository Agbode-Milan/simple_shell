#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct list_s - Singly linked list
 * @str: String (malloc'ed string)
 * @next: Points to the next node
 *
 * Description: Singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct info_s - Information struct
 * @argc: Argument count
 * @argv: Argument vector
 * @history: List containing command history
 * @alias: List containing aliases
 *
 * Description: Struct to hold information and variables
 */
typedef struct info_s
{
	int argc;
	int readfd;
	char **argv;
	list_t *history;
	list_t *alias;
} info_t;

int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);
void delete_node_at_index(list_t **list, unsigned int index);
unsigned int get_node_index(list_t *list, const char *str);
list_t *node_starts_with(list_t *list, const char *str, char delimiter);
void add_node_end(list_t **list, const char *str);
list_t *get_node_at_index(list_t *list, unsigned int index);

#endif

