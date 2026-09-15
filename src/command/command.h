/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:44:51 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/15 14:54:24 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "../string/string.h"

// echo.c

void	command_echo(const char *str);

// pwd.c

void	command_pwd(const char *command);

#endif
