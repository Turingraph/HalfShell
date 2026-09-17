/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:31:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 12:32:30 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

// time : O(1)
// space: O(1)
void	write_total_score(size_t score, size_t max_score)
{
	write(1, "Score: ", 8);
	ft_putnbr_fd((int)score, 1, "0123456789", 1);
	write(1, " / ", 3);
	ft_putnbr_fd((int)max_score, 1, "0123456789", 1);
	write(1, "\n", 1);
}

// time : O(n)
// space: O(n)
void	warning_file_not_exists(const char *src)
{
	write(1, "Warning: ", 10);
	write(1, src, f_strlen(src));
	write(1, " is not exists.\n", 17);
}
