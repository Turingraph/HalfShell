/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:44:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/14 17:50:21 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	word_in_quote(const char *str, int fd, bool is_write)
{
	int	i;

	if (str == NULL || *str != '\'' || *str != '"')
		return (0);
	i = 1;
	while (str[i] != '\0' && str[i] != str[0])
	{
		if (is_write == true)
			write(fd, str + i, 1);
		i += 1;
	}
	if (str[i] == '\0')
		return (-1 * (i + 1));
	return (i);
}

bool	is_stop_char(char a)
{
	if (a == '\0')
		return (true);
	return (is_a_in_arr(a, "<>|&;"));
}

size_t	word_out_quote(const char *str, int fd, bool is_write)
{
	size_t	i;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	while (is_stop_char(str[i]) == false && str[i] != ' ')
	{
		if (is_write == true)
			write(fd, str + i, 1);
		i += 1;
	}
	return (i);
}

bool	parse_word_unit(const char *str, size_t *i, int fd, bool is_write)
{
	int		word_length;

	while (str[*i] == ' ')
		*i += 1;
	if (str[*i] == '\'' || str[*i] == '"')
	{
		word_length = word_in_quote(str + *i, fd, is_write);
		if (word_length < 0)
			return (false);
		*i += (size_t)word_length;
	}
	else if (is_stop_char(str[*i]) == false)
		*i += word_out_quote(str + *i, fd, is_write);
	else
		return (false);
	return (true);
}

size_t	parse_words(const char *str, int fd, bool is_write)
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
		continue_loop = parse_word_unit(str, *i, fd, is_write);
		if (continue_loop == true)
		{
			if (is_write == true)
				write(fd, " ", 1);
			y += 1;
		}
	}
	return (y);
}
