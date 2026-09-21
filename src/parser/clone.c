#include "parser.h"

char	*clone_word_in_quote(const char *str)
{
	int		i;
	char	*dst;
	int		length;

	if (str == NULL || (*str != '\'' && *str != '\"'))
		return (NULL);
	length = word_in_quote(str, -2);
	if (length < 0)
		length *= -1;
	length -= 1;
	dst = malloc_talk(sizeof(char) * (length + 1), "clone_word_in_quote\n");
	if (dst == NULL)
		return (NULL);
	dst[length] = '\0';
	if (dst == NULL)
		return (NULL);
	i = 1;
	while (str[i] != '\0' && str[i] != str[0])
	{
		dst[i - 1] = str[i];
		i += 1;
	}
	return (dst);
}

char	*clone_word_out_quote(const char *str)
{
	size_t	i;
	char	*dst;
	int		length;

	if (str == NULL || *str == '\0' || is_a_in_str(*str, " \'\"") == true)
		return (NULL);
	length = word_out_quote(str, -2);
	dst = malloc_talk(sizeof(char) * (length + 1), "close_word_out_quote\n");
	if (dst == NULL)
		return (dst);
	dst[length] = '\0';
	i = 0;
	while (is_stop_char(str[i]) == false
		&& is_a_in_str(str[i], " \'\"") == false)
	{
		dst[i] = str[i];
		i += 1;
	}
	return (dst);
}

char	*clone_word_outin_quote(const char *str)
{
	size_t	length_out;
	size_t	length_in;

	length_in = word_in_quote(str, -2);
	length_out = word_out_quote(str, -2);
	if (length_in > length_out)
		return (clone_word_in_quote(str));
	return (clone_word_out_quote(str));
}
