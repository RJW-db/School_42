/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:43:58 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/30 14:21:49 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	// char s[20] = "Hello World!";
// 	char s[20] = "Hello\0 World!";
//	//
// 	printf("%p\n", ft_strchr(s, 'W'));
// 	printf("%p\n", strchr(s, 'W'));
// 	printf("%s\n", ft_strchr(s, 'W' + 256));
// 	return (0);
//	//
// 	// char s[] = "tripouille";
// 	// printf("%p\n", ft_strchr(s, 0));
//     // return (0);
// }
