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

# include "../string/string.h"

typedef enum t_write_style
{
	WRITE_NEW,
	WRITE_ONLY_NEW,
	WRITE_NO_NEW,
	WRITE_NOTHING,
}	t_write_style;

// cd.c

void	command_cd(const char *command);

// echo.c

void	command_echo(const char *str);

// pwd.c

void	command_pwd(const char *command);

#endif
