/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:44:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 19:06:02 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * Extract the content of a quoted word.
 * The string must start with either a single or double quote.
 * Writes the characters inside the quotes to fd when fd is valid.
 *
 * Returns the offset of the closing quote.
 * Returns a negative value when the closing quote is missing.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param str quoted string to parse
 * @param fd file descriptor to write the word to, or -1 to disable output
 *
 * @return offset of the closing quote, or a negative value on an unclosed quote
 */
int	word_in_quote(const char *str, int fd)
{
	int		i;
	char	a;

	if (str == NULL || (*str != '\'' && *str != '\"'))
		return (0);
	i = 1;
	while (str[i] != '\0' && str[i] != str[0])
	{
		a = str[i];
		if (fd > -1)
			write(fd, &a, 1);
		i += 1;
	}
	if (str[i] == '\0')
		return (-1 * (i + 1));
	return (i);
}

/**
 * Check whether a character marks the end of a word.
 * The null terminator is also considered a stop character.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param a character to check
 *
 * @return true if a is a stop character, otherwise false
 */
bool	is_stop_char(char a)
{
	if (a == '\0')
		return (true);
	return (is_a_in_str(a, "<>|&;"));
}

/**
 * Extract a word outside of quotes.
 * Stops when a space, quote, shell operator, meta character
 * or null terminator is reached.
 * Writes the characters to fd when fd is valid.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param str string containing the word to parse
 * @param fd file descriptor to write the word to, or -1 to disable output
 *
 * @return number of characters consumed from str
 */
size_t	word_out_quote(const char *str, int fd)
{
	size_t	i;

	if (str == NULL || *str == '\0' || is_a_in_str(*str, " \'\"") == true)
		return (0);
	i = 0;
	while (is_stop_char(str[i]) == false
		&& is_a_in_str(str[i], " \'\"") == false)
	{
		if (fd > -1)
			write(fd, str + i, 1);
		i += 1;
	}
	return (i);
}

bool	parse_word_unit(const char *str, size_t *i, int fd)
{
	int		word_length;

	while (str[*i] == ' ')
		*i += 1;
	if (is_a_in_str(str[*i], "\'\"") == true)
	{
		word_length = word_in_quote(str + *i, fd);
		if (word_length < 0)
			return (false);
		*i += (size_t)word_length;
	}
	else if (is_stop_char(str[*i]) == false)
		*i += word_out_quote(str + *i, fd);
	else
		return (false);
	return (true);
}

size_t	parse_words(const char *str, int fd)
{
	size_t	y;
	size_t	i;
	bool	continue_loop;

	if (str == NULL || *str == '\0')
		return (0);
	continue_loop = true;
	y = 0;
	i = 0;
	while (continue_loop == true)
	{
		continue_loop = parse_word_unit(str, &i, fd);
		if (continue_loop == true)
		{
			if (fd > -1)
				write(fd, " ", 1);
			y += 1;
		}
	}
	return (y);
}
