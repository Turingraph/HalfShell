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
		stop = word_in_quote(user_command + start, -2);
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
