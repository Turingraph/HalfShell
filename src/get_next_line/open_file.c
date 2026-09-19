#include "get_next_line.h"

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
