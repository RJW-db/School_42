/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:23:10 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 21:25:20 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int	main(void)
// {
// 	char str[20] = "Hello, World!";
// 	printf("%s\n", str);
// 	ft_bzero(str + 3, 5);
// 	write(1, str, 13);
// 	return (0);
// }
