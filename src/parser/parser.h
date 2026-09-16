/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:45:32 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/14 17:45:41 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../string/string.h"

// get_ith.c

size_t	get_ith_arg(const char *a, size_t i);

// parser.c

bool	parse_word_unit(const char *str, size_t *i, int fd, bool is_write);
size_t	parse_words(const char *str, int fd, bool is_write);

#endif
