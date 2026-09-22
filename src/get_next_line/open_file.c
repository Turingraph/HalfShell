#include "get_next_line.h"

/**
 * Open a file using an optional directory and file name.
 * Uses whichever path argument is provided when the other is NULL.
 * Concatenates both paths when both are provided.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param file_name name or path of the file to open
 * @param dir directory or path prefix of the file
 * @param file_mode file access mode
 *
 * @return file descriptor on success, or -1 on failure
 */
int	open_dir_file(const char *file_name, const char *dir, t_file_mode file_mode)
{
	t_dynamic_str	file;
	int				dst;

	if (dir == NULL && file_name == NULL)
		return (-1);
	if (dir == NULL && file_name != NULL)
		return (open(file_name, file_mode));
	if (dir != NULL && file_name == NULL)
		return (open(dir, file_mode));
	file = init_dynamic_str(
			index_a_in_str(file_name, '\0') + index_a_in_str(dir, '\0'));
	concat_dynamic_str(&file, dir);
	concat_dynamic_str(&file, file_name);
	if (file.str == NULL)
		return (-1);
	dst = open(file.str, file_mode);
	free(file.str);
	return (dst);
}

void	write_fetch_head(int input_fd, int first_n_line, int output_fd, bool is_new_line)
{
	size_t			i;
	size_t			new_line;
	t_dynamic_str	dst;

	if (input_fd < -1 || first_n_line == 0)
		return ;
	dst = init_dynamic_str(1);
	if (dst.str == NULL)
		return ;
	fetch_text(input_fd, &dst, BUFFER_SIZE);
	if (dst.str == NULL)
		return ;
	if (first_n_line < 0)
	{
		first_n_line = (int)how_many_a_in_str(dst.str, '\n') + first_n_line;
		if (dst.str[dst.length - 1] != '\n')
			first_n_line += 1;
	}
	new_line = 0;
	i = 0;
	while ((int)new_line < first_n_line && i < dst.length)
	{
		if (dst.str[i] == '\n')
			new_line += 1;
		write(output_fd, dst.str + i, 1);
		i += 1;
	}
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

// void	write_fetch_tail(int input_fd, size_t last_n_line, int output_fd)
