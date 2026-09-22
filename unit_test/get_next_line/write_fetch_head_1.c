#include "get_next_line.h"

int	main(void)
{
	size_t						i;
	size_t						score;
	size_t						max_score = 12;
	static const t_fetch_text_tester	arr[] = {
		{"41_no_nl", "01234567890123456789012345678901234567890"},
		{"41_with_nl", "0123456789012345678901234567890123456789\n"},
		{"42_no_nl", "012345678901234567890123456789012345678901"},
		{"42_with_nl", "01234567890123456789012345678901234567890\n"},
		{"43_no_nl", "0123456789012345678901234567890123456789012"},
		{"43_with_nl", "012345678901234567890123456789012345678901\n"},
		{"alternate_line_nl_no_nl", "98765432109876543210987654321098765432109\n"},
		{"alternate_line_nl_with_nl", "01234567890123456789012345678901234567890\n"},
		{"multiple_line_no_nl", "01234567890123456789012345678901234567890\n"},
		{"multiple_line_with_nl", "9876543210987654321098765432109876543210\n"},
		{"multiple_nlx5", "\n"},
		{"nl", "\n"}
	};
	char	*dir = "unit_test/get_next_line/input/";
	char	*output_dir = "unit_test/get_next_line/output/write_fetch_head_1.txt";
	int				input_file;
	int				output_file;
	char			*output_gnl;

	i = 0;
	score = 0;
	output_file = open_dir_file(output_dir, NULL, APPEND);
	while (i < max_score)
	{
		input_file = open_dir_file(arr[i].file_name, dir, READ);
		write_fetch_head(input_file, 1, output_file, true);
		close(input_file);
		i += 1;
	}
	close(output_file);
	i = 0;
	output_file = open_dir_file(output_dir, NULL, READ);
	while (i < max_score)
	{
		output_gnl = get_next_line(output_file, true, '\n');
		if (f_strlen(output_gnl) - f_strlen(arr[i].first_line) < 2
			&& is_2_str_same(output_gnl, arr[i].first_line, f_strlen(arr[i].first_line), false) == true)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, "\n", 1);
		}
		free(output_gnl);
		i += 1;
	}
	free(get_next_line(output_file, false, '\n'));
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/get_next_line/write_fetch_head_1.out

Reference
*	https://github.com/kodpe/gnl-station-tester
*	https://github.com/Tripouille/gnlTester
*/
