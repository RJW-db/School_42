/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:28:09 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:28:09 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (8);
	return (0);
}

// int	main(void)
// {
// 	int	i = 65;
// 	printf("%d\n",isalnum(i));
// 	printf("%d\n",ft_isalnum(i));
// 	return (0);
// }
