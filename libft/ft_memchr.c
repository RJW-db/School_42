/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:33:24 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 19:43:30 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (n--)
		if (((unsigned char *)s)[i++] == (unsigned char)c)
			return ((void *)(s + --i));
	return (NULL);
}

// int	main(void)
// {
// 	char	s1[30] = "Hello World!\0not an answer";
// 	char	s2[30] = "Hello World!\0not an answer";

// 	int		i = 55;
// 	char	*result1 = memchr(s1, 'a', i);
// 	printf("%s\n", result1);
// 	char	*result2 = ft_memchr(s2, 'a', i);
// 	printf("%s\n", result2);
// 	return (0);
// }
