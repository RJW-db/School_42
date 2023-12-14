/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:22:40 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 19:16:58 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	if (!*nptr)
		return (0);
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			flag *= -1;
	while (*nptr >= '0' && *nptr <= '9')
		i = i * 10 + (*nptr++ - '0');
	return (i * flag);
}

// int	main(void)
// {
// 	// char convert[] = "+ \t \v -123 abc";
// 	// char convert[] = " \t \v - 123ABC";
// 	// char convert[] = " \t \v + 123ABC";
// 	// char convert[] = " \t \v +123ABC";
// 	// char convert[] = "";
// 	// char convert[] = "123123123132";
// 	char convert[] = " \t \v -123ABC";
// 	printf("%d\n", atoi(convert));
// 	printf("%d\n", ft_atoi(convert));

// 	return (0);
// }
