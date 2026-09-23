#include "parser.h"

/**
 * Create the string based on the content of a quoted word.
 * The string must start with either a single or double quote.
 * Writes the characters inside the quotes to fd when fd is valid.
 *
 * time/space: O(n) / O(n)
 *
 * status: internal helper
 *
 * @param str quoted string to parse
 *
 * @return offset of the closing quote, or a negative value on an unclosed quote
 */
static char	*clone_in_quote(const char *str)
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
	dst = malloc_talk(sizeof(char) * (length + 1), "clone_in_quote\n");
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

/**
 * Create the string based on a word outside of quotes.
 * Stops when a space, quote, shell operator, meta character
 * or null terminator is reached.
 *
 * time/space: O(n) / O(n)
 *
 * status: internal helper
 *
 * @param str string containing the word to parse
 *
 * @return number of characters consumed from str
 */
static char	*clone_out_quote(const char *str)
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

/**
 * Create the string based on a word that might be inside or outside of quotes.
 * Stops when a space, quote, shell operator, meta character
 * (that outside the quotes) or null terminator is reached.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param str string containing the word to parse
 * @param fd file descriptor to write the word to, or -1 to disable output
 *
 * @return number of characters consumed from str
 */
char	*clone_outin_quote(const char *str)
{
	size_t	length_out;
	size_t	length_in;

	length_in = word_in_quote(str, -2);
	length_out = word_out_quote(str, -2);
	if (length_in > length_out)
		return (clone_in_quote(str));
	return (clone_out_quote(str));
}

/**
 * Extract a word that might be inside or outside of quotes.
 * Stops when a space, quote, shell operator, meta character
 * (that outside the quotes) or null terminator is reached.
 * Writes the characters to fd when fd is valid.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param str string containing the word to parse
 * @param fd file descriptor to write the word to, or -1 to disable output
 *
 * @return number of characters consumed from str.
 * Return negative number if the input str is inside the quote,
 * but ending quote isn't exists.
 */
int	word_outin_quote(const char *str, int fd)
{
	int	length_out;
	int	length_in;

	length_in = word_in_quote(str, -2);
	length_out = word_out_quote(str, -2);
	if (length_in > length_out)
		return (word_in_quote(str, fd));
	return (word_out_quote(str, fd));
}
