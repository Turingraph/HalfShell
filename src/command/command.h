/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:44:51 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/15 18:28:27 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "../get_next_line/get_next_line.h"
# include "../parser/parser.h"

// cd.c

void	command_echo(const char *command, int fd);
void	command_cd(const char *command, int fd);
void	command_pwd(const char *command, int fd);

#endif
