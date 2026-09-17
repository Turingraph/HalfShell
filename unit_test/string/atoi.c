#include"string.h"

// time : O(1)
// space: O(1)
bool	assert_atoi(const char *strmin, const char *strmax, bool *err)
{
	int		min;
	int		max;

	min = f_atoi(strmin, err, "0123456789", f_strlen(strmin));
	max = f_atoi(strmax, err, "0123456789", f_strlen(strmax));
	if (err != NULL && *err == false)
		return (false);
	if (min <= max)
		return (true);
	return (false);
}

int	main(void)
{
	size_t						i;
	size_t						score;
	size_t						max_score;
	bool						err;
	static const t_atoi_tester	arr[] = {
		{"5890", "5896", true, true},
		{"00820", "8230", true, true},
		{"0118", "jjij", false, false},
		{"jko", "-8509", false, false},
		{"2147483647", "2147483647", true, true},
		{"2147483644", "2147483648", false, false},
		{"557", "5557D", false, false},
		{"3524", "-3522", false, true},
		{"-8111", "-18441", false, true},
		{"0000774", "7764", true, true},
		{"71074", "7764", false, true},
		{"414", "4314", true, true},
		{"0", "0", true, true},
		{"-2819", "-2819", true, true},
		{"-2819", "0", true, true},
		{"0000462", "0004627", true, true}
	};

	max_score = 16;
	i = 0;
	score = 0;
	while (i < max_score)
	{
		err = true;
		if (assert_atoi(arr[i].min_input, arr[i].max_input, &err) == arr[i].is_eq_or_less
			&& arr[i].is_number == err)
			score += 1;
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/string/atoi.out
*/