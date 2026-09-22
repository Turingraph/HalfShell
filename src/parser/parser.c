/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:44:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 19:12:05 by phsottat         ###   ########.fr       */
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
	if (str[i] != str[0])
		i *= -1;
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

/**
 * Parse one word unit from a string.
 * Skips leading spaces, then parses either a quoted or unquoted word.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api (unfinished)
 *
 * @param str string to parse
 * @param i current position in str; updated by the number of characters consumed
 * @param fd file descriptor to write the parsed word to, or -1 to disable output
 *
 * @return true if a word unit was the last word successfully, otherwise false
 */
bool	parse_word_unit(const char *str, size_t *i, int fd)
{
	int		word_length;
	size_t	j;

	j = 0;
	if (i != NULL)
		j = *i;
	if (str[j] != '\0' && is_a_in_str(str[j], "\'\"") == true
		&& str[j] != str[j + 1])
	{
		word_length = word_in_quote(str + j, fd);
		if (word_length < 0)
		{
			j += (size_t)(-1 * word_length);
			if (i != NULL)
				*i = j;
			return (false);
		}
		j += (size_t)word_length + 1;
	}
	else if (is_stop_char(str[j]) == false)
		j += word_out_quote(str + j, fd);
	else
		return (false);
	if (i != NULL)
		*i = j;
	return (true);
}

/**
 * Parse all word units contained in a string.
 * Each successfully parsed word is separated by a space when fd is valid.
 *
 * Parsing stops when no more word units can be consumed or when an
 * unclosed quoted word is encountered.
 *
 * The return value depends on output_mode:
 * - ALL_CHARS returns the total number of characters that consumed by this function.
 * - ALL_ARGS returns the number of successfully parsed word units
 * (a.k.a. number of all arguments).
 * - ITH_ARG returns the character offset of the word at first_y.
 * 
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param str string to parse
 * @param fd file descriptor to write the parsed words to,
 * or -1 to disable output
 * @param first_y the first group of string that is displayed.
 * @param output_mode determines what value is returned
 *
 * @return number of number of all characters, number of all arguments,
 * or offset of the word at first_y depending on output_mode
 */
size_t	parse_words(const char *str, int fd, size_t first_y, t_arg_index output_mode)
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
		while ((str[i] == '\'' && str[i + 1] == '\'')
			|| (str[i] == '\"' && str[i + 1] == '\"') || str[i] == ' ')
			i += 1;
		if (y == first_y && output_mode == ITH_ARG)
			return (i);
		if (y < first_y)
			continue_loop = parse_word_unit(str, &i, -2);
		else
			continue_loop = parse_word_unit(str, &i, fd);
		if (continue_loop == true)
		{
			if (fd > -1 && y >= first_y && is_stop_char(str[i]) == false)
				write(fd, " ", 1);
			y += 1;
		}
	}
	if (output_mode == ALL_ARGS)
		return (y);
	return (i);
}

// Write comment about the 4th argument of parse_words.
/*
To Do List
1.	get i-th argument
2.	dquote >

Command
1.	cat
2.	head
3.	echo
4.	pwd
5.	env
6.	cd
7.	exit (with return value)

*/