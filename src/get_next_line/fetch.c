#include"get_next_line.h"

size_t	count_non_empty_lines(const char *src)
{
	size_t	y;

	y = how_many_a_in_str(src, '\n');
	if (src != NULL && src[f_strlen(src) - 1] != '\n')
		y += 1;
	return (y);
}

size_t	write_fetch(size_t first_line, size_t total_lines, const char *src, int fd)
{
	size_t	new_line;
	size_t	i;

	if (src == NULL)
		return (0);
	i = 0;
	new_line = 0;
	while (src[i] != '\0' && new_line < total_lines)
	{
		if (first_line <= new_line && fd > -2)
			write(fd, src + i, 1);
		if (src[i] == '\n')
			new_line += 1;
		i += 1;
	}
	return (i);
}

void	write_fetch_head(int input_fd, int first_n_line,
	int output_fd, bool is_new_line)
{
	size_t			i;
	t_dynamic_str	dst;

	dst = init_dynamic_str(1);
	if (dst.str == NULL)
		return ;
	fetch_text(input_fd, &dst, BUFFER_SIZE);
	if (dst.str == NULL)
		return ;
	if (first_n_line <= 0)
		first_n_line = (int)count_non_empty_lines(dst.str) + first_n_line;
	i = 0;
	if (first_n_line >= 0)
		i = write_fetch(0, first_n_line, dst.str, output_fd);
	if (i > 1 && dst.str[i - 1] != '\n' && is_new_line == true)
		write(output_fd, "\n", 1);
	free(dst.str);
}

void	write_fetch_tail(int input_fd, int last_n_line,
	int output_fd, bool is_new_line)
{
	size_t			i;
	t_dynamic_str	dst;

	dst = init_dynamic_str(1);
	if (dst.str == NULL)
		return ;
	fetch_text(input_fd, &dst, BUFFER_SIZE);
	if (dst.str == NULL)
		return ;
	if (last_n_line < 0 && last_n_line > -2147483648)
		last_n_line *= -1;
	else if (last_n_line == -2147483648)
		last_n_line = 2147483647;
	last_n_line = (int)count_non_empty_lines(dst.str) - last_n_line;
	if (last_n_line < 0)
		last_n_line = 0;
	i = write_fetch(last_n_line, count_non_empty_lines(dst.str), dst.str, output_fd);
	if (i > 1 && dst.str[i - 1] != '\n' && is_new_line == true)
		write(output_fd, "\n", 1);
	free(dst.str);
}

void	write_fetch_cat(int input_fd, int output_fd)
{
	t_dynamic_str	dst;

	if (input_fd < -1)
		return ;
	dst = init_dynamic_str(1);
	if (dst.str == NULL)
		return ;
	fetch_text(input_fd, &dst, BUFFER_SIZE);
	if (dst.str == NULL)
		return ;
	write(output_fd, dst.str, f_strlen(dst.str));
	free(dst.str);
}
