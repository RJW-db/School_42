/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:31:52 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 19:25:12 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

// int	main(void)
// {
// 	int c = 126;

// 	if (ft_isprint(c))
// 	{
// 		printf("\"%c\" is printable\n", c);
// 		printf("%d\n", isprint(c));
// 		printf("%d\n", ft_isprint(c));
// 	}
// 	else
// 	{
// 		printf("Not printable\n");
// 		printf("%d\n", isprint(c));
// 		printf("%d\n", ft_isprint(c));
// 	}
// 	return (0);
// }
