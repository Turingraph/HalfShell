#include"string.h"

int	main(void)
{
	size_t						        i;
	size_t						        score;
	size_t						        max_score = 17;
	static const t_2_str_same_tester	arr[] = {
		{"Hello", "Hello", 5, false, true},
		{"Hello", "Hello", 5, true, true},
		{"Hello ", "Hello", 6, false, false},
		{"Hello ", "Hello", 6, true, false},
		{" Hello", "Hello", 5, false, false},
		{" Hello", "Hello", 5, true, false},
		{" Hello ", "Hello", 5, false, false},
		{" Hello ", "Hello", 5, true, false},
		{"", "", 0, true, true},
		{"", "", 0, false, true},
		{"", "abc", 0, false, false},
		{"", "abc", 1, false, false},
		{"Hello ", "Hello", 6, false, false},
		{"Hello ", "Hell4", 4, false, true},
		{"Hello ", "Hell4", 4, true, false},
		{" Hello", " Hello", 3, false, true},
		{" Hello", " Hello", 3, true, false},
	};

	i = 0;
	score = 0;
	while (i < max_score)
	{
		if (is_2_str_same(arr[i].str_a, arr[i].str_b, arr[i].length, arr[i].check_space) == arr[i].answer)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, "\n", 1);
		}
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/string/is_2_str_same.out
*/