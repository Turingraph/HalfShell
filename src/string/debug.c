/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:31:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 18:44:04 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

/**
 * Display total debugging score. Ideally, the score should equal to max_score.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param score the actual score
 * @param max_score the ideal score. Also score <= max_score.
 */
void	write_total_score(size_t score, size_t max_score)
{
	write(1, "Score: ", 8);
	ft_putnbr_fd((int)score, 1, "0123456789", 1);
	write(1, " / ", 3);
	ft_putnbr_fd((int)max_score, 1, "0123456789", 1);
	write(1, "\n", 1);
}

/**
 * Display that the file isn't exists.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param src the name of the file
 */
void	warning_file_not_exists(const char *src)
{
	write(1, "Warning: ", 10);
	write(1, src, f_strlen(src));
	write(1, " is not exists.\n", 17);
}
