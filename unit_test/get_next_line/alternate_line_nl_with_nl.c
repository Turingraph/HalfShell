#include "get_next_line.h"

int	main(void)
{
	size_t						i;
	size_t						score;
	size_t						max_score = 9;
	char	*arr[] = {
		"01234567890123456789012345678901234567890\n",
		"\n",
		"987654321098765432109876543210987654321090\n",
		"\n",
		"0123456789012345678901234567890123456789012\n",
		"\n",
		"987654321098765432109876543210987654321090\n",
		"\n",
		"01234567890123456789012345678901234567890\n"
	};
	char	*dir = "unit_test/get_next_line/input/alternate_line_nl_with_nl";
	char	*dst;
	int				input_file;

	input_file = open_dir_file(NULL, dir, READ);
	i = 0;
	score = 0;
	while (i < max_score)
	{
		dst = get_next_line(input_file, true, '\n');
		if (is_2_str_same(arr[i], dst, f_strlen(arr[i]), false) == true)
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
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/get_next_line/alternate_line_nl_with_nl.out
*/
