/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:58:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 16:35:56 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"

int	main(void)
{
	size_t						        i;
	size_t						        score;
	size_t						        max_score = 20;
	char    *input_str[] = {
        "echo hello world",
        "               echo       hello world",
        "echo \'hello                       world       \'",
        "\'echo\' \'hello        \'        world",
        "        pwd \'\"\"\"\'",
        "        pwd \'\"\"\"\'       \'\"\"\"\'            \'\"\"\"\'       \'\"\"\"\'",
        "Johan                 \'\"\"\"\'        Yoasobi",
        "Jammmmmmmmmmm                            \"mmmmm\"",
        "echo \"Welcome to the Internet\"                   >>           google",
        "echo \"Welcome to the Internet\"                  \">>\'\"           google",
        "echo \"Welcome to the Internet\"                  \">>\'           google",
        "echo \"Welcome to the Internet\"                  \'>>\'           google",
        "         \'          ",
        "\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'",
        "                           Joooooooooooooooooooooooooooooooooooo Jooooooooooooooooooooooooo       ",
        "          \'                  ",
        "             \'exit exit\'             \"            ehehehe\"",
        "          infinite monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. ",
        "          \"infinite               monkey\" typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. ",
        "          infinite               monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. "
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