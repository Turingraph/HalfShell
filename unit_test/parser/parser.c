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
	char    *expect_str[] = {
        "echo hello world",                                  // 0
        "echo hello world",                                  // 1
        "echo hello                       world       ",     // 2
        "echo hello         world",                          // 3
        "pwd \"\"\"",                                        // 4    
        "pwd \"\"\" \"\"\" \"\"\" \"\"\"",                   // 5
        "Johan \"\"\" Yoasobi",                              // 6
        "Jammmmmmmmmmm mmmmm",                               // 7
        "echo Welcome to the Internet",                      // 8
        "echo Welcome to the Internet >>\' google",          // 9
        "echo Welcome to the Internet >>\'           google",// 10
        "echo Welcome to the Internet >> google",            // 11
        "          ",                                                  // 12    
        "",                                                  // 13    
        "Joooooooooooooooooooooooooooooooooooo Jooooooooooooooooooooooooo",
        "                  ",
        "exit exit             ehehehe",
        "infinite monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals.",
        "infinite               monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals.",
        "infinite monkey typing this keyboard without using LLM and ironically that human are ape with large biomass compared to most mammals."
    };
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
     char    *gnl_output;
    int     output;
    char    *file_name = "unit_test/parser/output/parser.txt";

	i = 0;
	score = 0;
    output = open_dir_file(file_name, NULL, APPEND);
	while (i < max_score)
	{
        parse_words(input_str[i], output);
        write(output, "\n", 1);
        i += 1;
	}
    close(output);
    output = open_dir_file(file_name, NULL, READ);
	i = 0;
	while (i < max_score)
    {
		gnl_output = get_next_line(output, true, '\n');
        if ((expect_str[i][0] == '\0' && (gnl_output[0] == '\0' || gnl_output[0] == '\n'))
            || is_2_str_same(expect_str[i], gnl_output, f_strlen(expect_str[i]), false) == true)
            score += 1;
        else
        {
            write(1, ">>> ", 4);
            ft_putnbr_fd(i, 1, "0123456789", 1);
            write(1, "\n", 1);
        }
        free(gnl_output);
        i += 1;
    }
    free(get_next_line(output, false, '\n'));
    close(output);
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/parser/parser.out
*/