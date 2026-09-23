/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:45:32 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/23 16:28:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../string/string.h"

typedef enum t_arg_index
{
	ALL_CHARS,
	ALL_ARGS,
	ITH_ARG
}	t_arg_index;

// clone.c

char	*clone_outin_quote(const char *str);
int		word_outin_quote(const char *str, int fd);

// parser.c

int	    word_in_quote(const char *str, int fd);
size_t	word_out_quote(const char *str, int fd);
bool	parse_word_unit(const char *str, size_t *i, int fd);
size_t	parse_words(const char *str, int fd, size_t first_y,
			t_arg_index output_mode);
bool	is_stop_char(char a);

// utils.c

bool	is_valid_command(const char *user_command, const char *keyword,
			size_t option_index);
int		command_to_integer(const char *user_command, size_t option_index,
			bool *is_int);
bool	too_many_arguments(const char *command, size_t limit);
bool	is_end_with_newline(const char *user_command);

#endif
