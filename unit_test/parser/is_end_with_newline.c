/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_end_with_newline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:58:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/23 15:54:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"

int	main(void)
{
	size_t						        i;
	size_t						        score;
	size_t						        max_score = 5 * 5;
	char    *input_str[] = {
    /* true,  00 */    "echo hello \'world",
    /* false, 01  */    "               echo       hello world",
    /* true,  02 */    "echo \'hello                       world       ",
    /* true,  03 */    "\'echo\' \'hello                world",
    /* false, 04  */    "        pwd \'\"\"\"\'",
    /* false, 05  */    "        pwd \'\"\"\"\'       \'\"\"\"\'            \'\"\"\"\'       \'\"\"\"\'",
    /* false, 06  */    "Johan                 \'\"\"\"\'        Yoasobi",
    /* false, 07  */    "Jammmmmmmmmmm                            \"mmmmm\"",
    /* true,  08 */    "echo \"Welcome to the Internet                   >>           google",
    /* false,  09 */    "echo \"Welcome to the Internet                  \">>\'\"           google",
    /* false, 10  */    "echo \"Welcome to the Internet\"                  \">>\'           google\"",
    /* false, 11  */    "echo \"Welcome to the Internet\"                  \'>>\'           google",
    /* true,  12 */    "         \'          ",
    /* false, 13 */    "\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'",
    /* true,  14 */    "                           Joooooooooooooooooooooooooooooooooooo \'Jooooooooooooooooooooooooo       ",
    /* true,  15 */    "          \'            \"      ",
    /* true,  16 */    "             \'exit exit\'             \"            ehehehe",
    /* true,  17 */    "          infinite monkey typing this keyboard without using LLM \'and ironically that human are ape with large biomass compared to most mammals. ",
    /* true,  18 */    "          \"infinite               monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. ",
    /* false  19 */    "          infinite               monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. ",
    /* true,  20 */    "\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'",
    /* true,  21 */    "\'",
    /* true,  22 */    "\'9\'\'",
    /* true,  23 */    "\'9",
    /* true,  24 */    "\'\'\'\'\'\'\'\'\'\'\'5\'\'\'\'\'\'\'\'\'\'",
    };
    bool    answer[] = {
        true,   // 00
        false,  // 01
        true,   // 02
        true,   // 03
        false,  // 04
        false,  // 05
        false,  // 06
        false,  // 07
        true,   // 08
        false,  // 09
        false,  // 10
        false,  // 11
        true,   // 12
        false,  // 13
        true,   // 14
        true,   // 15
        true,   // 16
        true,   // 17
        true,   // 18
        false,  // 19
        true,   // 20
        true,   // 21
        true,   // 22
        true,   // 23
        true,   // 24
    };

    i = 0;
	score = 0;
	while (i < max_score)
	{
        if (is_end_with_newline(input_str[i]) == answer[i])
            score += 1;
        else
        {
            write(1, ">>> ", 4);
            ft_putnbr_fd(i, 1, "0123456789", 1);
            write(1, "\t", 1);
            ft_putnbr_fd(parse_words(input_str[i], -2, 0, ALL_ARGS), 1, "0123456789", 1);
            write(1, "\n", 1);
        }
        i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/parser/is_end_with_newline.out
*/