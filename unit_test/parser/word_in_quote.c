/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_in_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:58:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 18:50:15 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"

int	main(void)
{
	size_t						        i;
	size_t						        score;
	size_t						        length_score;
	size_t						        max_score = 16;
	char    *str[] = {
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
	char    *str_2[] = {
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
    char    *gnl_output;
    int     output;
    char    *output_dir = "unit_test/parser/output/";
    char    *file_name = "word_in_quote.txt";
    int        length_output;

	i = 0;
    length_score = 0;
	score = 0;
    output = open_dir_file(file_name, output_dir, APPEND);
	while (i < max_score)
	{
        length_output = word_in_quote(str[i], output);
        if ((int)f_strlen(str[i]) == length_output + 1 || how_many_a_in_str(str[i], str[i][0]) > 2)
            length_score += 1;
        write(output, "\n", 1);
        i += 1;
	}
    close(output);
    output = open_dir_file(file_name, output_dir, READ);
	i = 0;
	while (i < max_score)
    {
		gnl_output = get_next_line(output, true, '\n');
        if (is_2_str_same(str_2[i], gnl_output, f_strlen(str_2[i]), false) == true || f_strlen(str_2[i]) == 0)
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
	write_total_score(length_score, max_score);
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/parser/word_in_quote.out
*/