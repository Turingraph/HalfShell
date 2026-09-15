/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:44:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/15 16:07:05 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

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

	if (is_2_str_meansame("pwd", command) == true)
	{
		getcwd(path, sizeof(path));
		write(1, path, f_strlen(path));
		write(1, "\n", 1);
	}
}
