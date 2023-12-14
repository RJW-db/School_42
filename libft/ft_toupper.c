/* ************************************************************************** */
/*	                                                                         */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 15:16:24 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 15:17:04 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

// int	main(void)
// {
// 	char c = 'a';
// 	printf("%c", ft_toupper(c));
// 	return (0);
// }
