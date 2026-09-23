/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_in_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:58:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/23 16:45:16 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"

int	main(void)
{
	size_t						        i;
	size_t						        score;
	size_t						        max_score = 16;
	char    *input_str[] = {
        "\"echo hello world\"",
        "\"echo hello                       world       \"",
        "\"echo hello                 world\"",
        "'pwd \"\"\"'",
        "'pwd \"\"\" \"\"\" \"\"\" \"\"\"'",
        "'Johan \"\"\" Yoasobi'",
        "'Jammmmmmmmmmm mmmmm'",
        "'Jammmmmmmmmmm mm'mmm'",
        "'echo Welcome to the Internet'",
        "\"echo Welcome to the Internet >> google\"",
        "\"echo Welcome to the I\"nternet >> google\"",
        "\"echo Welcome to the Internet >>'           google\"",
        "'echo Welcome to the Internet >>'",
        "''",
        "\"'''''''''''''''''''''\"",
        "'Joooooooooooooooooooooooooooooooooooo Jooooooooooooooooooooooooo'"
    };
	char    *expect_str[] = {
        "echo hello world",
        "echo hello                       world       ",
        "echo hello                 world",
        "pwd \"\"\"",
        "pwd \"\"\" \"\"\" \"\"\" \"\"\"",
        "Johan \"\"\" Yoasobi",
        "Jammmmmmmmmmm mmmmm",
        "Jammmmmmmmmmm mm",
        "echo Welcome to the Internet",
        "echo Welcome to the Internet >> google",
        "echo Welcome to the I",
        "echo Welcome to the Internet >>'           google",
        "echo Welcome to the Internet >>",
        "",
        "'''''''''''''''''''''",
        "Joooooooooooooooooooooooooooooooooooo Jooooooooooooooooooooooooo"
    };
    char    *output;

	i = 0;
	score = 0;
	while (i < max_score)
    {
        output = clone_outin_quote(input_str[i]);
        if (is_2_str_same(output, expect_str[i], f_strlen(expect_str[i]), false) == true
            && f_strlen(expect_str[i]) == f_strlen(output))
            score += 1;
        free(output);
        i += 1;
    }
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/parser/clone_in_quote.out
*/