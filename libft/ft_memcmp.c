/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:33:30 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/30 13:36:30 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	// char	a[] = "ac";
// 	// char	b[] = "ZZ";

// 	// char	a[] = "aaa\0c";
// 	// char	b[] = "aaa\0b";

// 	char	a[] = "aaa\200a";
// 	char	b[] = "aaa\200z";
// 	unsigned int n = 5;

// 	printf("%d\n", memcmp(a, b, n));
// 	printf("%d\n", ft_memcmp(a, b, n));
// }
