/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:19:21 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/23 19:09:26 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/halfshell.h"

void	new_line_shell(char **user_command)
{
	t_dynamic_str	buff;
	int				activate;
	char			*command;

	activate = 1;
	if (user_command == NULL || *user_command == NULL)
		return ;
	buff = init_dynamic_str(1);
	if (buff.str == NULL)
		return ;
	concat_dynamic_str(&buff, (const char *)*user_command);
	free(*user_command);
	while (activate == 1)
	{
		command = readline("> ");
		concat_dynamic_str(&buff, "\n");
		concat_dynamic_str(&buff, (const char *)command);
		free(command);
		*user_command = buff.str;
		if (is_end_with_newline(*user_command) == false)
			activate = 0;
	}
}

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
		else if (is_end_with_newline(command) == true)
			new_line_shell(&command);
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