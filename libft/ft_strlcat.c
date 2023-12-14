/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:49:20 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:49:20 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dst_len > size)
		return (ft_strlen(src) + size);
	return (dst_len + ft_strlcpy(dst + dst_len, src, size - dst_len));
}

// int	main(void)
// {
// 	char	src[] = "Foo Bars Bazs";
// 	char	dst[18] = "Baz";
// 	printf("%ld\n", ft_strlcat(dst, src, sizeof(dst)));
// 	printf("%s\n", dst);

// 	return (0);
// }
