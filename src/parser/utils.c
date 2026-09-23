/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:53:13 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/23 15:50:43 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * Check whether a specific argument of a command matches a keyword.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param user_command command string to inspect
 * @param keyword expected argument value
 * @param option_index index of the argument to compare. 0 is the first index.
 *
 * @return true if the requested argument matches keyword, otherwise false
 */
bool	is_valid_command(const char *user_command, const char *keyword,
	size_t option_index)
{
	size_t	start;
	int		stop;

	if (user_command == NULL || keyword == NULL)
		return (false);
	start = parse_words(user_command, -2, option_index, ITH_ARG);
	if (user_command[start] == '\'' || user_command[start] == '\"')
	{
		stop = word_in_quote(user_command + start, -2) - 1;
		start += 1;
	}
	else if (user_command[start] == *keyword)
		stop = (int)word_out_quote(user_command + start, -2);
	else
		return (false);
	if (stop < 0 || is_2_str_same(user_command + start,
			keyword, stop, false) == false)
		return (false);
	return (true);
}

/**
 * Convert a specific command argument to an integer.
 *
 * The is_int output parameter is set to false when the command is NULL
 * or when the requested argument isn't valid representation of decimal nuber.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param user_command command string to inspect
 * @param option_index index of the argument to convert. 0 is the first index.
 * @param is_int output flag indicating whether the conversion is valid
 *
 * @return converted integer, or -1 when the argument cannot be converted
 */
int	command_to_integer(const char *user_command,
	size_t option_index, bool *is_int)
{
	size_t	start;
	int		stop;

	if (user_command == NULL)
	{
		if (is_int != NULL)
			*is_int = false;
		return (-1);
	}
	stop = 0;
	start = parse_words(user_command, -2, option_index, ITH_ARG);
	if (user_command[start] == '\'' || user_command[start] == '\"')
	{
		stop = word_in_quote(user_command + start, -2);
		start += 1;
	}
	else if (is_a_in_str(user_command[start], "0123456789-") == true)
		stop = (int)word_out_quote(user_command + start, -2);
	else
	{
		if (is_int != NULL)
			*is_int = false;
		return (-1);
	}
	return (f_atoi(user_command + start, is_int, "0123456789", stop));
}

/**
 * Check whether a command contains more arguments than allowed.
 *
 * When the argument limit is exceeded, the first argument is printed
 * as the command name in a Bash-like error message.
 *
 * parse_words() counts only successfully parsed word units. Therefore,
 * malformed trailing input, such as an unclosed quote, is not included
 * in the returned argument count.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param command command string to inspect
 * @param limit maximum number of allowed arguments
 *
 * @return true if the command contains more than limit arguments,
 * otherwise false
 */
bool	too_many_arguments(const char *command, size_t limit)
{
	size_t	arg_counts;
	size_t	first_arg;

	arg_counts = parse_words(command, -2, 0, ALL_ARGS);
	first_arg = parse_words(command, -2, 0, ITH_ARG);
	if (command != NULL && arg_counts > limit)
	{
		write(1, "bash: ", 6);
		parse_word_unit(command + first_arg, NULL, 1);
		write(1, ": too many arguments\n", 21);
		return (true);
	}
	return (false);
}

/**
 * Check whether the last successfully parsed argument is followed by
 * an unclosed quoted word.
 *
 * ALL_ARGS returns the number of successfully parsed word units. If the
 * final word is malformed because its closing quote is missing, that
 * word is not included in the count.
 *
 * For example, if a command contains two valid arguments followed by
 * a last unclosed quoted word argument, ALL_ARGS returns 2
 * and ITH_ARG(2) points to the beginning of the unclosed quoted word.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param user_command command string to inspect
 *
 * @return true if the command ends with an unclosed quote, otherwise false
 */
bool	is_end_with_newline(const char *user_command)
{
	size_t	count_args;
	size_t	start;
	int		y;

	count_args = parse_words(user_command, -2, 0, ALL_ARGS);
	start = parse_words(user_command, -2, count_args, ITH_ARG);
	if (user_command[start] == '\'' || user_command[start] == '\"')
	{
		y = (int)word_in_quote(start + user_command, -2);
		if (y <= 0)
			return (true);
		return (false);
	}
	return (false);
}
