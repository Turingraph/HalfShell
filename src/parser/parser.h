/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:45:32 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 18:27:00 by phsottat         ###   ########.fr       */
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

// parser.c

int	    word_in_quote(const char *str, int fd);
size_t	word_out_quote(const char *str, int fd);
bool	parse_word_unit(const char *str, size_t *i, int fd);
size_t	parse_words(const char *str, int fd, size_t first_y,
			t_arg_index output_mode);

#endif
