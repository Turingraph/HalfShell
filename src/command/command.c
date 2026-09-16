#include "src.h"

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
void	command_cd(const char *command)
{
	if (is_1st_str_same("cd", command) == true)
	{
		if (parse_words())
	}

	if (is_2_str_same("cd ", command, 3) == true && f_strlen(command) > 3)
	{
		if (chdir(command + 3) != 0)
		{
			write(1, "cd: no such file or directory: ", 31);
			write(1, command + 3, f_strlen(command + 3));
			write(1, "\n", 1);
		}
	}
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
void	command_pwd(const char *command)
{
	char	path[255];

	if (is_1st_str_same("pwd", command) == true)
	{
		getcwd(path, sizeof(path));
		write(1, path, f_strlen(path));
		write(1, "\n", 1);
	}
}
