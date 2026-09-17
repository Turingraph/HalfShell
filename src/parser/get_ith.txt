#include "parser.h"

size_t	get_ith_arg(const char *a, size_t i)
{
	size_t	y;
	size_t	i;
	size_t	j;
	bool	continue_loop;

	if (str == NULL || *str == '\0')
		return (0);
	continue_loop = true;
	y = 0;
	i = 0;
	while (continue_loop == true && y < i)
	{
		j = i;
		continue_loop = parse_word_unit(str, *i, 1, false);
		if (continue_loop == true)
			y += 1;
	}
	return (j);
}

/*
List of separator (meta character)
1.	word
*	$
2.	sentence
*	;, &, |, >, <

To Do List
1.	get and comparing the i-th argument
2.	execute cd, echo, and pwd
3.	> and >>
4.	echo with new line

*/
