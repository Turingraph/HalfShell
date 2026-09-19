#include "get_next_line.h"

int	main(void)
{
	size_t						i;
	size_t						score;
	size_t						max_score = 13;
	static const t_fetch_text_tester	arr[] = {
		{"41_no_nl", "01234567890123456789012345678901234567890"},
		{"41_with_nl", "0123456789012345678901234567890123456789\n"},
		{"42_no_nl", "012345678901234567890123456789012345678901"},
		{"42_with_nl", "01234567890123456789012345678901234567890\n"},
		{"43_no_nl", "0123456789012345678901234567890123456789012"},
		{"43_with_nl", "012345678901234567890123456789012345678901\n"},
		{"alternate_line_nl_no_nl", "98765432109876543210987654321098765432109\n"},
		{"alternate_line_nl_with_nl", "01234567890123456789012345678901234567890\n"},
		{"empty", ""},
		{"multiple_line_no_nl", "01234567890123456789012345678901234567890\n"},
		{"multiple_line_with_nl", "9876543210987654321098765432109876543210\n"},
		{"multiple_nlx5", "\n"},
		{"nl", "\n"}
	};
	char	*dir = "unit_test/get_next_line/input/";
	char	*dst;
	int				input_file;

	i = 0;
	score = 0;
	while (i < max_score)
	{
		input_file = open_dir_file(arr[i].file_name, dir, READ);
		dst = get_next_line(input_file, false, '\n');
		if (is_2_str_same(arr[i].first_line, dst, f_strlen(arr[i].first_line), false) == true)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, "\t", 1);
			ft_putnbr_fd(f_strlen(dst), 1, "0123456789", 1);
			write(1, "\t", 1);
			write(1, dst, f_strlen(dst));
			write(1, "\n", 1);
		}
		close(input_file);
		free(dst);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/get_next_line/get_first_line.out
*/
