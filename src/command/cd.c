/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:44:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/15 16:12:09 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

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
