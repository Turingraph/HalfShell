#include "command.h"

void	command_echo(const char *command, int fd)
{
	if(is_valid_command(command, "echo", 0) == true
		&& is_valid_command(command, "-n", 1) == false)
	{
		parse_words(command, fd, 1, ALL_ARGS);
		write(fd, "\n", 1);
	}
	else if (is_valid_command(command, "echo", 0) == true
		&& is_valid_command(command, "-n", 1) == true)
		parse_words(command, fd, 2, ALL_ARGS);
}

/**
 * change the directory of the process.
 * 
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @see 
 * - https://www.geeksforgeeks.org/linux-unix/chdir-in-c-language-with-examples/
 */
void	command_cd(const char *command, int fd)
{
	char	*dir;

	dir = NULL;
	if(is_valid_command(command, "cd", 0) == true
		&& too_many_arguments(command, 2) == false)
	{
		dir = clone_word_outin_quote(
				parse_words(command, -2, 1, ITH_ARG) + command);
		if (dir != NULL && chdir(dir) != 0)
		{
			write(fd, "cd: no such file or directory: ", 31);
			write(fd, dir, f_strlen(dir));
			write(fd, "\n", 1);
		}
	}
	free(dir);
}

/**
 * Execute the pwd command without any option.
 * 
 * time/space: O(s, where s <= 255) / O(1)
 *
 * status: public api
 *
 * @param command complete echo command to execute
 * @see https://stackoverflow.com/questions/298510/
 * how-to-get-the-current-directory-in-a-c-program for more
 * details about how to implement this function.
 */
void	command_pwd(const char *command, int fd)
{
	char	path[255];

	if (is_valid_command(command, "pwd", 0) == true)
	{
		getcwd(path, sizeof(path));
		write(fd, path, f_strlen(path));
		write(fd, "\n", 1);
	}
}

/*
Command list
1.	echo
2.	cd
3.	pwd
4.	head
5.	tail
6.	cat
7.	export
8.	unset
9.	env
10.	exit
*/