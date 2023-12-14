/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_full_width.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 19:00:35 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/12/07 01:25:44 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libext.h"

#define MARKUP "\033[1;32m"
#define MARKDOWN "\033[0m\n"

//	#include <sys/ioctl.h>
void	print_full_width(const int c)
{
	struct winsize	w;
	const int		markup = strlen_esc(MARKUP);
	const int		markdown = strlen_esc(MARKDOWN);
	char			*chr;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	chr = (char *)malloc((w.ws_col + markup + markdown + 1));
	ft_memcpy(chr, MARKUP, markup);
	ft_memset(chr + markup, c, w.ws_col);
	ft_strlcpy(chr + markup + w.ws_col, MARKDOWN, markdown + 1);
	ft_putstr_fd(chr, STDOUT_FILENO);
	free(chr);
}
