#include "get_next_line.h"

size_t	index_a_in_str(const char *src, char a)
{
	size_t	i;

	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == a)
			return (i + 1);
		i += 1;
	}
	return (i);
}

void	fetch_text(int fd, t_dynamic_str *dst, size_t buffer_length)
{
	char	*buff;
	bool	continue_line;

	continue_line = true;
	while (continue_line == true && dst != NULL && dst->str != NULL)
	{
		buff = clone_string(sizeof(char) * buffer_length, NULL);
		if (buff == NULL)
			continue_line = false;
		else
		{
			read(fd, buff, buffer_length);
			concat_dynamic_str(dst, buff);
			if (index_a_in_str(buff, '\0') < buffer_length)
				continue_line = false;
		}
		free(buff);
	}
}

char	*get_next_line2(int fd, bool is_continue, char stop_char)
{
	char			*dst;
	static char		*prev_str = NULL;
	t_dynamic_str	dyn_str;
	size_t			length;

	dyn_str = init_dynamic_str(1);
	if (dyn_str.str == NULL)
		return (NULL);
	concat_dynamic_str(&dyn_str, prev_str);
	if (prev_str == NULL)
		fetch_text(fd, &dyn_str, BUFFER_SIZE);
	free(prev_str);
	prev_str = NULL;
	length = index_a_in_str(dyn_str.str, stop_char);
	dst = clone_string(length, dyn_str.str);
	if (is_continue == true)
		prev_str = clone_string(dyn_str.length - length, dyn_str.str + length);
	else
		close(fd);
	free(dyn_str.str);
	return (dst);
}

char	*get_next_line(int fd)
{
	return (get_next_line2(fd, true, '\n'));
}