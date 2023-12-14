/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:43:43 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:43:43 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int	main(void)
// {
// 	char	*s = "abcdef";
// 	// int		fd = open("info.txt", O_WRONLY);
// 	int		fd = open("info.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);

// 	ft_putstr_fd(s, fd);
// 	return (0);
// }