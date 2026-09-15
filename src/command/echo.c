/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:44:07 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/15 14:40:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

/**
 * Print a string to stdout following basic echo formatting.
 *
 * Leading spaces are ignored. When the string contains no double quotes,
 * only the first word is printed. When the string is enclosed by a pair
 * of double quotes, the characters inside the quotes are printed.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param str string to parse and print
 */
void	command_echo_message(const char *str)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] == ' ')
		i += 1;
	if (is_contains_n_as((const char *)str, '"', 0) == true)
	{
		while (str[i] != '\0' && str[i] != ' ')
		{
			write(1, str + i, 1);
			i += 1;
		}
	}
	else if (str[i] == '"'
		&& is_contains_n_as((const char *)str, '"', 2) == true)
	{
		i += 1;
		while (str[i] != '\0' && str[i] != '"')
		{
			write(1, str + i, 1);
			i += 1;
		}
	}
}

/**
 * Execute the echo command with optional newline suppression.
 *
 * Recognizes the `echo` command and the `-n` flag, then delegates
 * message output to command_echo_message(const char *str).
 * A newline is printed unless the `-n` flag is present.
 *
 * This implementation handles a simplified echo syntax and does not
 * handle pipes or other shell features.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param command complete echo command to execute
 */
void	command_echo(const char *command)
{
	if (is_2_str_same("echo -n ", command, 8))
		command_echo_message(command + 8);
	else if (is_2_str_same("echo ", command, 5))
	{
		command_echo_message(command + 5);
		write(1, "\n", 1);
	}
}
