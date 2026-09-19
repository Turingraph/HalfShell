#include "get_next_line.h"

char	*clone_string(size_t length, const char *src)
{
	size_t	i;
	char	*dst;

	if (length == 0)
		return (NULL);
	dst = (void *)malloc((length + 1) * sizeof(char));
	if (dst == NULL)
		return (dst);
	dst[length] = '\0';
	i = 0;
	while (i < length && src != NULL && src[i] != '\0')
	{
		dst[i] = src[i];
		i += 1;
	}
	while (i < length)
	{
		dst[i] = 0;
		i += 1;
	}
	return (dst);
}

t_dynamic_str	init_dynamic_str(size_t length)
{
	t_dynamic_str	dst;

	dst.capacity = length;
	dst.length = 0;
	dst.str = NULL;
	if (length == 0)
		return (dst);
	dst.str = clone_string(sizeof(char) * length, NULL);
	return (dst);
}

bool	push_dynamic_str(t_dynamic_str *dst, char src)
{
	char	*dst2;

	if (dst == NULL || dst->str == NULL)
		return (false);
	if (dst->length < dst->capacity)
	{
		dst->str[dst->length] = src;
		dst->length += 1;
		return (true);
	}
	dst2 = clone_string(sizeof(char) * 2 * dst->length, dst->str);
	if (dst2 == NULL)
		return (false);
	free(dst->str);
	dst->str = dst2;
	dst->capacity *= 2;
	return (push_dynamic_str(dst, src));
}

void	concat_dynamic_str(t_dynamic_str *dst, const char *src)
{
	size_t	i;
	bool	is_continue;

	if (dst == NULL || dst->str == NULL || src == NULL)
		return ;
	is_continue = true;
	i = 0;
	while (src[i] != '\0' && is_continue == true)
	{
		is_continue = push_dynamic_str(dst, src[i]);
		i += 1;
	}
}
