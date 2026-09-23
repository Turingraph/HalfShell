/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_end_with_newline_false.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:58:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/23 15:57:19 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"

int	main(void)
{
	size_t						        i;
	size_t						        score;
	size_t						        max_score = 20;
	char    *input_str[] = {
    /* 00 */    "echo hello world",
    /* 01 */    "               echo       hello world",
    /* 02 */    "echo \'hello                       world       \'",
    /* 03 */    "\'echo\' \'hello        \'        world",
    /* 04 */    "        pwd \'\"\"\"\'",
    /* 05 */    "        pwd \'\"\"\"\'       \'\"\"\"\'            \'\"\"\"\'       \'\"\"\"\'",
    /* 06 */    "Johan                 \'\"\"\"\'        Yoasobi",
    /* 07 */    "Jammmmmmmmmmm                            \"mmmmm\"",
    /* 08 */    "echo \"Welcome to the Internet\"                   >>           google",
    /* 09 */    "echo \"Welcome to the Internet\"                  \">>\'\"           google",
    /* 10 */    "echo \"Welcome to the Internet\"            \"      \">>           google",
    /* 11 */    "echo \"Welcome to the Internet\"                  \'>>\'           google",
    /* 12 */    "         \'   \"  \'     ",
    /* 13 */    "\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\"\"",
    /* 14 */    "                           Joooooooooooooooooooooooooooooooooooo Jooooooooooooooooooooooooo       ",
    /* 15 */    "\'          \'                  ",
    /* 16 */    "             \'exit exit\'             \"            ehehehe\"",
    /* 17 */    "          infinite monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. ",
    /* 18 */    "          \"infinite               monkey\" typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. ",
    /* 19 */    "          infinite               monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. "
    };

    i = 0;
	score = 0;
	while (i < max_score)
	{
        if (is_end_with_newline(input_str[i]) == false)
            score += 1;
        else
        {
            write(1, ">>> ", 4);
            ft_putnbr_fd(i, 1, "0123456789", 1);
            write(1, "\n", 1);
        }
        i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/parser/is_end_with_newline_false.out
*/