/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:19:21 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/15 18:53:13 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/halfshell.h"

int	main(void)
{
	char	*command;
	int		activate;

	activate = 1;
	while (activate == 1)
	{
		command = readline("minishell $ ");
		if (is_valid_command(command, "exit", 0) == true)
			activate = 0;
		command_echo(command, 1);
		command_cd(command, 1);
		command_pwd(command, 1);
		command_head(command, 1);
		command_tail(command, 1);
		command_cat(command, 1);
		free(command);
	}
	return (0);
}

/*
cc -Wall -Wextra -Werror -lreadline main.c
valgrind --leak-check=full --show-leak-kinds=all ./halfshell
*/

/*
Thing to do
1.	cd, echo, pwd, command, export, unset, env,
2.	>>, >
3.	return value of shell (error vs not error)
4.	?

Thing not to do (yet)
1.	pip '|'
2.	<, << (last step)
3.	?

keyword
1.	heredoc*/