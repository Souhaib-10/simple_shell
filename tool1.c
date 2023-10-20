#include "shell.h"

/**
 * display_history - Displays the history list, one command by line,
 * preceded with line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int display_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Unsets an alias.
 * @info: Parameter struct.
 * @alias_str: The alias string.
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *alias_str)
{
	char *p, c;
	int ret;

	p = _strchr(alias_str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, alias_str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Sets an alias to a string.
 * @info: Parameter struct.
 * @alias_str: The alias string.
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *alias_str)
{
	char *p;

	p = _strchr(alias_str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, alias_str));

	unset_alias(info, alias_str);
	return (add_node_end(&(info->alias), alias_str, 0) == NULL);
}

/**
 * print_alias - Prints an alias string.
 * @alias_node: The alias node.
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *alias_node)
{
	char *p = NULL, *a = NULL;

	if (alias_node)
	{
		p = _strchr(alias_node->str, '=');
		for (a = alias_node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * manage_alias - Manages aliases, mimicking the alias builtin.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int manage_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *alias_node = NULL;

	if (info->argc == 1)
	{
		alias_node = info->alias;
		while (alias_node)
		{
			print_alias(alias_node);
			alias_node = alias_node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

