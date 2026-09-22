#include "command.h"

void	count_head_loop(const char *command, int fd, int first_line, size_t first_file)
{
	char	*file_name;
	size_t	count_args;
	int		input_fd;
	size_t	i;

	i = first_file;
	count_args = parse_words(command, -2, 0, ALL_ARGS);
	while (i < count_args)
	{
		file_name = clone_word_outin_quote(parse_words(command, -2, i, ITH_ARG) + command);
		input_fd = open_dir_file(file_name, NULL, READ);
		if (count_args - first_file > 1 && file_name != NULL)
		{
			if (i > first_file)
				write(fd, "\n==> ", 5);
			else
				write(fd, "==> ", 4);
			write(fd, file_name, f_strlen(file_name));
			write(fd, " <==\n", 5);
		}
		write_fetch_head(input_fd, first_line, fd, false);
		free(file_name);
		close(input_fd);
		i += 1;
	}
}

void	command_head(const char *command, int fd)
{
	int		count_line;
	bool	is_int;
	size_t	first_file;

	is_int = true;
	first_file = 1;
	count_line = 10;
	if(is_valid_command(command, "-n", 1) == true
		&& is_valid_command(command, "head", 0) == true)
	{
		first_file = 3;
		count_line = command_to_integer(command, 2, &is_int);
	}
	if (is_int == false)
	{
		write(fd, "head : invalid number of lines: `", 33);
		word_outin_quote(parse_words(command, -2, 2, ITH_ARG) + command, fd);
		write(fd, "`\n", 2);
	}
	else
		count_head_loop(command, fd, count_line, first_file);
}
