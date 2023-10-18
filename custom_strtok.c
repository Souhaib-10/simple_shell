#include "shell.h"

/**
 * _custom_strtok - Tokenizes a string into tokens using specified delimiters.
 * @str: The string to tokenize.
 * @delim: The delimiter characters.
 * Return: The first/next token if possible, NULL otherwise.
 */
char *_custom_strtok(char *str, const char *delim)
{
	static char *next;

	if (str != NULL)
		next = str;
	else if (next == NULL)
		return (NULL);

	str = next + _custom_strspn(next, delim);
	next = str + _custom_strcspn(str, delim);

	if (*next != '\0')
	{
		*next = '\0';
		next++;
	}
	else
	{
		next = NULL;
	}

	return (str);
}

/**
 * _custom_strcspn - Computes the length of the maximum initial segment
 * of a string that consists entirely of characters not in another string.
 * @s1: The string to check.
 * @s2: The string used for comparison.
 * Return: The length of the segment.
 */
size_t _custom_strcspn(const char *s1, const char *s2)
{
	size_t length = 0;

	while (*s1 != '\0')
	{
		if (_custom_strchr(s2, *s1) == NULL)
			return (length);

		s1++;
		length++;
	}

	return (length);
}

/**
 * _custom_strspn - Computes the length of the maximum initial segment
 * of a string that consists entirely of characters in another string.
 * @s1: The string to compute the length.
 * @s2: The string used for delimiting.
 * Return: The length of the segment.
 */
size_t _custom_strspn(const char *s1, const char *s2)
{
	size_t length = 0;

	while (*s1 != '\0' && _custom_strchr(s2, *s1) != NULL)
	{
		s1++;
		length++;
	}

	return (length);
}

/**
 * _custom_strchr - Locates the first occurrence of a character in a string.
 * @s: The string to search.
 * @c: The character to find.
 * Return: A pointer to the located character, or NULL if not found.
 */
char *_custom_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}

	return ((char *)s);
}
