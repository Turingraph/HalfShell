#include "include/halfshell.h"

// volatile is used for making OS stop optimizing the program,
// such that the program might works slower but more correctly.
// sig_atomic_t is just the data type that you are allowed to use in the
//  context of a signal handler. It is usually an int type.
// the g_activation is used for making client wait before the server
// finishing processing the individual bits, so both 2 programs are synchronized
// and thus works more reliable.
// https://stackoverflow.com/questions/24931456/
// how-does-sig-atomic-t-actually-work
volatile sig_atomic_t	g_activation = 1;

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
char	is_2_str_same(const char *a, const char *b)
{
	size_t	i;

	if (a == NULL && b == NULL)
		return (1);
	if (a == NULL || b == NULL)
		return (0);
	i = 0;
	while (a[i] == b[i] && a[i] != '\0')
		i += 1;
	if (a[i] != b[i])
		return (0);
	return (1);
}

// https://medium.com/@levequeloris66/what-are-the-signals-in-c-3208d86c183e
void	stop_func(volatile int signum)
{
	char	*listenner;

	listenner = readline("\nminishell $ ");
	if (signum == SIGINT)
	{
		if (is_2_str_same("exit", listenner) == true)
			g_activation = 0;
		free(listenner);
	}
}

// ft_putnbr_fd write the PID of this server.
int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = stop_func;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
	while (g_activation == 1)
		pause();
	return (0);
}

/*
cc -Wall -Wextra -Werror -lreadline main.c
valgrind --leak-check=full --show-leak-kinds=all ./a.out
*/
