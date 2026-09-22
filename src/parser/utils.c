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

int	command_to_integer(const char *user_command, size_t option_index, bool *is_int)
{
	size_t	start;
	int		stop;

	if (user_command == NULL)
	{
		if (is_int != NULL)
			*is_int = false;
		return (-1);
	}
	stop = 0;
	start = parse_words(user_command, -2, option_index, ITH_ARG);
	if (user_command[start] == '\'' || user_command[start] == '\"')
	{
		stop = word_in_quote(user_command + start, -2);
		start += 1;
	}
	else if (is_a_in_str(user_command[start], "0123456789-") == true)
		stop = (int)word_out_quote(user_command + start, -2);
	else
	{
		if (is_int != NULL)
			*is_int = false;
		return (-1);
	}
	return (f_atoi(user_command + start, is_int, "0123456789", stop));
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

/**
 * status: Always return false when it work unexpectedly.
 * No Valgrind reported memory leak.
 */
bool	is_end_with_newline(const char *user_command)
{
	size_t	count_args;
	size_t	start;
	int		y;

	count_args = parse_words(user_command, -2, 0, ALL_ARGS);
	if (count_args == 0)
		return (false);
	write(1, "--- ", 4);
	ft_putnbr_fd(count_args, 1, "0123456789", 1);
	write(1, "\n", 1);
	start = parse_words(user_command, -2, count_args - 1, ITH_ARG);
	if (user_command[start] == '\'' || user_command[start] == '\"')
	{
		y = (int)word_in_quote(start + user_command, -2);
		write(1, "+++ ", 4);
		write(1, start + user_command, f_strlen(start + user_command));
		write(1, "#\n\n", 3);
		if (y <= 0)
		{
			// write(1, "\nYorushika\n", 11);
			return (true);
		}
		// write(1, "\nNujabes\n", 9);
		return (false);
	}
	return (false);
}
