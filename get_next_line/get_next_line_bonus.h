/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/29 11:35:24 by rjw           #+#    #+#                 */
/*   Updated: 2023/12/07 13:31:53 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define MAX_FDS 1024

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

char	*get_next_line(int fd);
size_t	str_len(const char *str);
int		cpy(char *dest, const char *src, bool *nl_check);
void	*free_str(char *str);

#endif