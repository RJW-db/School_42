/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libext.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/29 11:35:24 by rjw           #+#    #+#                 */
/*   Updated: 2023/12/13 04:21:25 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBEXT_H
# define LIBEXT_H

# include "libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <time.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	strlen_esc(const char *s);

//	File Descriptor and I/O Functions
int		ft_writing(const char *str, int n);
int		ft_writing_fd(const char *str, int n, int fd);
void	print_full_width(const int c);
void	exe_time(clock_t start_time);
void	markup(char *str, ...);
char	*strjoin_free(const char *s1, const char *s2);
char	*strjoin_va(const char *fmt, ...);

#endif