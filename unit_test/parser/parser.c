/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:58:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/23 14:23:03 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"

int	main(void)
{
	size_t						        i;
	size_t						        score;
	size_t						        char_score;
	size_t						        args_score;
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
    size_t      args_expect[] = {
        3,// 0
        3,// 0
        2,// 0
        3,// 0
        2,// 0
        5,// 1
        3,// 1
        2,// 1
        2,// 1
        4,// 1
        2,
        4,
        0,
        0,
        2,
        0,
        2,
        21,
        20,
        21
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
    size_t  answer_char;

    char_score = 0;
    args_score = 0;
	i = 0;
	score = 0;
    output = open_dir_file(file_name, NULL, APPEND);
	while (i < max_score)
	{
        if (parse_words(input_str[i], output, 0, ALL_ARGS) == args_expect[i])
            args_score += 1;
        else
        {
            write(1, ";;; ", 4);
            ft_putnbr_fd(i, 1, "0123456789", 1);
            write(1, "\t", 1);
            ft_putnbr_fd(args_expect[i], 1, "0123456789", 1);
            write(1, "\t", 1);
            ft_putnbr_fd(parse_words(input_str[i], -2, 0, ALL_ARGS), 1, "0123456789", 1);
            write(1, "\n", 1);
        }
        answer_char = parse_words(input_str[i], -2, 0, ALL_CHARS);
        if (answer_char == f_strlen(input_str[i]))
            char_score += 1;
        else if ((i == 8 && answer_char == f_strlen("echo \"Welcome to the Internet\"                   ")))
            char_score += 1;
        else
        {
            write(1, "::: ", 4);
            ft_putnbr_fd(i, 1, "0123456789", 1);
            write(1, "\t", 1);
            ft_putnbr_fd(f_strlen(input_str[i]), 1, "0123456789", 1);
            write(1, "\t", 1);
            ft_putnbr_fd(answer_char, 1, "0123456789", 1);
            write(1, "\n", 1);
        }
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
	write_total_score(args_score, max_score);
	write_total_score(char_score, max_score);
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/parser/parser.out
*/