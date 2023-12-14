/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:30:12 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:30:12 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}

// int	main(void)
// {
// 	int	i = 65;
// 	if (ft_isalpha(i))
// 	{
// 		printf("\"%c\" is in the alphabet\n", i);
// 		printf("%d\n", isalpha(i));
// 		printf("%d\n", ft_isalpha(i));
// 	}
// 	else
// 	{
// 		printf("Not in alphabet\n");
// 		printf("%d\n", isalpha(i));
// 		printf("%d\n", ft_isalpha(i));
// 	}
// 	return (0);
// }
