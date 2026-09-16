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
bool	is_2_str_same(const char *a, const char *b, size_t length, bool check_space)
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
	if (check_space == false)
		return (true);
	if (check_space == true && (b[i] == '\0' || b[i] == ' '))
		return (true);
	return (false);
}

// time : O(n)
// space: O(1)
bool	is_a_in_arr(char a, const char *arr)
{
	while (arr != NULL && *arr != '\0')
	{
		if (*arr == a)
			return (true);
		arr += 1;
	}
	return (false);
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
