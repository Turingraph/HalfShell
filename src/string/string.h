/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:31:12 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/15 16:06:39 by phsottat         ###   ########.fr       */
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

// string.c

size_t	f_strlen(const char *str);
bool	is_2_str_same(const char *a, const char *b, size_t length);
bool	is_contains_n_as(const char *src, char a, size_t n);
bool	is_a_in_arr(char a, const char *arr);
void	*malloc_talk(size_t elem_size, const char *comment);

#endif
