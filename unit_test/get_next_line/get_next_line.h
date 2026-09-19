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

#ifndef GET_NEXT_LINE_TESTER_H
# define GET_NEXT_LINE_TESTER_H

# include "../../src/get_next_line/get_next_line.h"
# include "../../src/string/string.h"

typedef struct t_concat_dynamic_str_tester
{
	char	*str_1;
	char	*str_2;
	char	*str_3;
}	t_concat_dynamic_str_tester;

typedef struct t_fetch_text_tester
{
	char	*file_name;
	char	*first_line;
}	t_fetch_text_tester;

#endif
