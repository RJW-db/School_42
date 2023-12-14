/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:54:39 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/24 19:43:39 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	a[] = "ab";
// 	char	b[] = "\200";	// man strncmp
// 	unsigned int n = 5;

// 	printf("%d\n", strncmp(a, b, n));
// 	printf("%d\n", ft_strncmp(a, b, n));
// 	// \200 is equal to 128 in char, and 128 char is higher than the max
//  	// 127 so it will become -128, and 129 would become -127.
// 	// with an unsigned char 128 would stay 128 because the limit is 255.
// }
