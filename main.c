#include "include/halfshell.h"

// time : O(n)
// space: O(1)
size_t	f_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str != NULL && *str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}

// time : O(n)
// space: O(1)
bool	is_2_str_same(const char *a, const char *b, size_t length)
{
	size_t	i;

	if (a == NULL && b == NULL)
		return (true);
	if (a == NULL || b == NULL)
		return (false);
	i = 0;
	while (a[i] != '\0' && i < length)
	{
		if (a[i] != b[i])
			return (false);
		i += 1;
	}
	return (true);
}

bool	is_contains_n_as(const char *src, char a, size_t n)
{
	size_t	i;
	size_t	y;

	if (src == NULL || src[0] == '\0')
		return (false);
	y = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == a)
			y += 1;
		i += 1;
	}
	if (y != n)
		return (false);
	return (true);
}

void	command_echo(const char *str)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] == ' ')
		i += 1;
	if (is_contains_n_as((const char *)str, '"', 0) == true)
	{
		while (str[i] != '\0' && str[i] != ' ')
		{
			write(1, str + i, 1);
			i += 1;
		}
	}
	else if (str[i] == '"'
		&& is_contains_n_as((const char *)str, '"', 2) == true)
	{
		i += 1;
		while (str[i] != '\0' && str[i] != '"')
		{
			write(1, str + i, 1);
			i += 1;
		}
	}
}

int	main(void)
{
	char	*listener;
	int		g_activation;

	g_activation = 1;
	while (g_activation == 1)
	{
		listener = readline("minishell $ ");
		if (listener == NULL)
			break ;
		else if (is_2_str_same("exit", listener, 4))
			g_activation = 0;
		else if (is_2_str_same("echo -n ", listener, 8))
			command_echo(listener + 8);
		else if (is_2_str_same("echo ", listener, 5))
		{
			command_echo(listener + 5);
			write(1, "\n", 1);
		}
		free(listener);
	}
	return (0);
}

/*
cc -Wall -Wextra -Werror -lreadline main.c
valgrind --leak-check=full --show-leak-kinds=all ./a.out
*/
