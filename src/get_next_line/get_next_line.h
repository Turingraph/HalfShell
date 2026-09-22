/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:36:58 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 12:52:32 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../string/string.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_dynamic_str
{
	size_t	length;
	size_t	capacity;
	char	*str;
}	t_dynamic_str;

typedef enum t_file_mode
{
	READ = O_RDONLY,
	APPEND = O_WRONLY | O_CREAT | O_APPEND,
}	t_file_mode;

// dynamic_str.c

char			*clone_string(size_t length, const char *src);
t_dynamic_str	init_dynamic_str(size_t length);
bool			push_dynamic_str(t_dynamic_str *dst, char src);
void			concat_dynamic_str(t_dynamic_str *dst, const char *src);
size_t			index_a_in_str(const char *src, char a);

// fetch.c

void			write_fetch_head(int input_fd, int first_n_line,
					int output_fd, bool is_new_line);
void			write_fetch_cat(int input_fd, int output_fd);

// get_next_line.c

void			fetch_text(int fd, t_dynamic_str *dst, size_t buffer_length);
char			*get_next_line(int fd, bool is_continue, char stop_char);

// open_dir_file.c

int				open_dir_file(const char *file_name,
					const char *dir, t_file_mode file_mode);

#endif
