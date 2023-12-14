/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:31:13 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:31:13 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(void)
// {
// 	int i = 127;
// 	if (ft_isascii(i))
// 	{
// 		printf("\"%c\" is in the ASCII table\n", i);
// 		printf("%d\n", isascii(i));
// 		printf("%d\n", ft_isascii(i));
// 	}
// 	else
// 	{
// 		printf("Not an ASCII character\n");
// 		printf("%d\n", isascii(i));
// 		printf("%d\n", ft_isascii(i));
// 	}
// 	return (0);
// }
