#include "get_next_line.h"

int	main(void)
{
	size_t						i;
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
	int				input_file;

	i = 0;
	while (i < max_score)
	{
		input_file = open_dir_file(arr[i].file_name, dir, READ);
		write_fetch_head(input_file, -1000, 1, true);
		close(input_file);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/get_next_line/write_fetch_head_minus100.out

Reference
*	https://github.com/kodpe/gnl-station-tester
*	https://github.com/Tripouille/gnlTester
*/
