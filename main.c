/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:19:21 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/15 15:42:59 by phsottat         ###   ########.fr       */
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
		if (command == NULL)
			break ;
		else if (is_2_str_same("exit", command, 4) == true)
			activate = 0;
		else if (is_2_str_same("echo ", command, 5) == true)
			command_echo(command);
		else if (is_2_str_same("pwd", command, 3) == true)
			command_pwd(command);
		free(command);
	}
	return (0);
}

/*
cc -Wall -Wextra -Werror -lreadline main.c
valgrind --leak-check=full --show-leak-kinds=all ./halfshell
*/
