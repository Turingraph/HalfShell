#include "parser.h"

bool	is_valid_command(const char *user_command, const char *keyword, size_t option_index)
{
	size_t	start;
	int		stop;

	if (user_command == NULL || keyword == NULL)
		return (false);
	start = parse_words(user_command, -2, option_index, ITH_ARG);
	if (user_command[start] == '\'' || user_command[start] == '\"')
	{
		stop = word_in_quote(user_command + start, -2) - 1;
		start += 1;
	}
	else if (user_command[start] == *keyword)
		stop = (int)word_out_quote(user_command + start, -2);
	else
		return (false);
	if (stop < 0 || is_2_str_same(user_command + start, keyword, stop, false) == false)
		return (false);
	return (true);
}

bool	too_many_arguments(const char *command, size_t limit)
{
	size_t	arg_counts;
	size_t	first_arg;

	arg_counts = parse_words(command, -2, 0, ALL_ARGS);
	first_arg = parse_words(command, -2, 0, ITH_ARG);
	if (command != NULL && arg_counts > limit)
	{
		write(1, "bash: ", 6);
		parse_word_unit(command + first_arg, NULL, 1);
		write(1, ": too many arguments\n", 21);
		return (true);
	}
	return (false);
}
