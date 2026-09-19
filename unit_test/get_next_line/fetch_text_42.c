#include "get_next_line.h"

int	main(void)
{
	size_t						i;
	size_t						score;
	size_t						max_score = 13;
	static const t_fetch_text_tester	arr[] = {
		{"41_no_nl", "01234567890123456789012345678901234567890"},
		{"41_with_nl", "0123456789012345678901234567890123456789\n0"},
		{"42_no_nl", "012345678901234567890123456789012345678901"},
		{"42_with_nl", "01234567890123456789012345678901234567890\n"},
		{"43_no_nl", "0123456789012345678901234567890123456789012"},
		{"43_with_nl", "012345678901234567890123456789012345678901\n2"},
		{"alternate_line_nl_no_nl", "98765432109876543210987654321098765432109\n"},
		{"alternate_line_nl_with_nl", "01234567890123456789012345678901234567890\n"},
		{"empty", ""},
		{"multiple_line_no_nl", "01234567890123456789012345678901234567890\n"},
		{"multiple_line_with_nl", "9876543210987654321098765432109876543210\n0"},
		{"multiple_nlx5", "\n\n\n\n\n"},
		{"nl", "\n"}
	};
	char	*dir = "unit_test/get_next_line/input/";
	t_dynamic_str	dst;
	int				input_file;

	i = 0;
	score = 0;
	while (i < max_score)
	{
		input_file = open_dir_file(arr[i].file_name, dir, READ);
		dst = init_dynamic_str(1);
		fetch_text(input_file, &dst, '\n', 42);
		if (is_2_str_same(arr[i].first_line, dst.str, f_strlen(arr[i].first_line), false) == true)
			score += 1;
		close(input_file);
		free(dst.str);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/get_next_line/fetch_text_42.out
*/

/*
To Do Now
1.	fix fetch_text
2.	redesign fetch_text
3.	fix gnl
*/