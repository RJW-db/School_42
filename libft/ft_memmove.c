/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:36:31 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 19:47:07 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;

	tmp = dest;
	if (src > dest)
		while (n--)
			*(char *)tmp++ = *(char *)src++;
	if (dest > src)
		while (n--)
			*((char *)dest + n) = *((char *)src + n);
	return (dest);
}

// int	main(void)
// {
// 	char str1[] = "123456789";
// 	char str2[] = "123456789";

// 	// memmove(str1 + 3, str1, 5);
// 	// ft_memmove(str2 + 3, str2, 5);

// 	memmove(str1 + 2, str1 + 5, 2);
// 	ft_memmove(str2 + 2, str2 + 5, 2);

// 	printf("%s\n", (char *)str1);
// 	printf("%s\n", (char *)str2);
// 	return (0);
// }
