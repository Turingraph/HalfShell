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
	size_t						        max_score = 18;
	char    *str[] = {
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
        "          infinite monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. "
        "          \"infinite               monkey\" typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. "
        "          infinite               monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals. "
    };
     char    *gnl_output;
    char    *gnl_expect;
    int     output;
    char    *output_dir = "unit_test/parser/";
    char    *expect_dir = "unit_test/parser/";
    char    *file_name = "word_in_quote.txt";
    int     expect;

	i = 0;
	score = 0;
    output = open_dir_file(file_name, output_dir, APPEND);
	while (i < max_score)
	{
        parse_words(str[i], output);
        write(output, "\n", 1);
        i += 1;
	}
    close(output);
    output = open_dir_file(file_name, output_dir, READ);
    expect = open_dir_file(file_name, expect_dir, READ);
	i = 0;
	while (i < max_score)
    {
		gnl_output = get_next_line(output, true);
		gnl_expect = get_next_line(expect, true);
        if (is_2_str_same(gnl_expect, gnl_output, f_strlen(gnl_expect), false) == true)
            score += 1;
        free(gnl_expect);
        free(gnl_output);
        i += 1;
    }
    get_next_line(output, false);
    get_next_line(expect, false);
    close(output);
    close(expect);
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/parser/parser.out
*/