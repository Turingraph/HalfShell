#include "get_next_line.h"

int	main(void)
{
	size_t						i;
	size_t						score;
	size_t						max_score = 7;
	static const t_concat_dynamic_str_tester	arr[] = {
		{"Tally ", "Hall", "Tally Hall"},
		{"Tally\"", "Hall", "Tally\"Hall"},
		{"42  ", " Coding School", "42   Coding School"},
		{"", "Jame", "Jame"},
		{"Jame", "", "Jame"},
		{"Jame", ".", "Jame."},
		{"Zutomay", "orushika", "Zutomayorushika"}
	};
	t_dynamic_str	dst;

	i = 0;
	score = 0;
	while (i < max_score)
	{
		dst = init_dynamic_str(f_strlen(arr[i].str_1) + f_strlen(arr[i].str_2));
		concat_dynamic_str(&dst, arr[i].str_1);
		concat_dynamic_str(&dst, arr[i].str_2);
		if (is_2_str_same(arr[i].str_3, dst.str, f_strlen(arr[i].str_3), false) == true)
			score += 1;
		free(dst.str);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/get_next_line/concat_dynamic_str.out
*/