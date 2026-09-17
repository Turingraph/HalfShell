/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:03:14 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 12:46:17 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_TESTER_H
# define STRING_TESTER_H

# include "../../src/string/string.h"

typedef struct t_atoi_tester
{
	char	*min_input;
	char	*max_input;
	bool	is_eq_or_less;
	bool	is_number;
}	t_atoi_tester;

typedef struct t_putnbr_tester
{
	int			input_n;
	size_t		input_digits;
	const char	*input_base;
	size_t		expected_length;
}	t_putnbr_tester;

typedef struct t_2_str_same_tester
{
	char	*str_a;
	char	*str_b;
	size_t	length;
	bool	check_space;
	bool	answer;
}	t_2_str_same_tester;

#endif
