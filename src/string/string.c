/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:31:36 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/15 16:06:03 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

/**
 * Return the length of a null-terminated string.
 * Returns 0 if str is NULL.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param str string to measure
 * 
 * @return number of characters in str, excluding the terminating '\0'
 */
size_t	f_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str != NULL && *str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}

/**
 * Check whether two strings contain the same characters up to a limit.
 *
 * NULL strings are considered equal only when both pointers are NULL.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param a first string to compare
 * @param b second string to compare
 * @param length maximum number of characters to compare
 *
 * @return true if the strings match up to length, otherwise false
 */
bool	is_2_str_same(const char *a, const char *b, size_t length)
{
	size_t	i;

	if (a == NULL && b == NULL)
		return (true);
	if (a == NULL || b == NULL)
		return (false);
	i = 0;
	while (a[i] != '\0' && i < length)
	{
		if (a[i] != b[i])
			return (false);
		i += 1;
	}
	return (true);
}

/**
 * Check whether two strings contain the same text followed only by spaces.
 * The first string must match the beginning of the second string exactly.
 * Any remaining characters in the second string must be spaces.
 * 
 * time/space: O(n) / O(1)
 * 
 * status: public api
 * 
 * @param a string used as the expected prefix
 * @param b string to compare against
 * @return true if b contains a followed only by spaces, otherwise false
 */
bool	is_2_str_meansame(const char *a, const char *b)
{
	size_t	i;

	if (is_2_str_same(a, b, f_strlen(a)) == false)
		return (false);
	if (b[f_strlen(a)] == '\0')
		return (true);
	i = 0;
	while (b[f_strlen(a) + i] != '\0')
	{
		if (b[f_strlen(a) + i] != ' ')
			return (false);
		i += 1;
	}
	return (true);
}

/**
 * Check whether a character occurs exactly n times in a string.
 *
 * Returns false when src is NULL or empty.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param src string to search
 * @param a character to count
 * @param n expected number of occurrences
 *
 * @return true if a occurs exactly n times in src, otherwise false
 */
bool	is_contains_n_as(const char *src, char a, size_t n)
{
	size_t	i;
	size_t	y;

	if (src == NULL || src[0] == '\0')
		return (false);
	y = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == a)
			y += 1;
		i += 1;
	}
	if (y != n)
		return (false);
	return (true);
}

/**
 * Allocate and initialize a memory block with zero values.
 * Print a message to stdout if allocation fails and comment is provided.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 * 
 * @param elem_size size of the memory block in bytes
 * @param comment message to print when allocation fails
 *
 * @return pointer to the initialized memory block, or NULL on failure
 */
void	*malloc_talk(size_t elem_size, const char *comment)
{
	size_t			i;
	unsigned char	*d;
	void			*dst;

	if (elem_size == 0)
		return (NULL);
	dst = (void *)malloc(elem_size);
	if (dst == NULL)
	{
		if (comment != NULL && *comment != '\0')
		{
			write(1, "Malloc Fail: ", 14);
			write(1, comment, f_strlen(comment));
		}
	}
	d = (unsigned char *)dst;
	i = 0;
	while (i < elem_size)
	{
		*d = 0;
		d += 1;
		i += 1;
	}
	return (dst);
}
