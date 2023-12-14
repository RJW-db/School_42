/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:31:31 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:31:31 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

// int	main(void)
// {
// 	int	i = 'a';
// 	if (ft_isdigit(i))
// 	{
// 		printf("%d\n", i);
// 		printf("%d\n", isdigit(i));
// 		printf("%d\n", ft_isdigit(i));
// 	}
// 	else
// 	{
// 		printf("Not a digit\n");
// 		printf("%d\n", isdigit(i));
// 		printf("%d\n", ft_isdigit(i));
// 	}
// 	return (0);
// }
