/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:31:12 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 18:41:27 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

// atoi.c

int		f_atoi(const char *src, bool *is_int, const char *base, size_t digits);
size_t	ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

// debug.c

void	write_total_score(size_t score, size_t max_score);
void	warning_file_not_exists(const char *src);

// string.c

size_t	how_many_a_in_str(const char *str, char a);
size_t	f_strlen(const char *str);
bool	is_2_str_same(const char *a, const char *b,
			size_t length, bool check_space);
bool	is_a_in_str(char a, const char *str);

#endif
