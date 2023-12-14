/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:54:58 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/24 20:34:55 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	if ((char)c == 0)
		return ((char *)s + i);
	return (0);
}

// int	main(void)
// {
// 	char s[20] = "Hello World!";

// 	printf("%s\n", ft_strrchr(s, 'o'));
// 	printf("%p\n", ft_strrchr(s, 0));
// 	printf("%p\n", s + ft_strlen(s));
// 	return (0);
// }
