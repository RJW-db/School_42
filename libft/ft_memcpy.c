/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 14:00:41 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/11/10 18:30:51 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp;

	tmp = dest;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*tmp++ = *(unsigned char *)src++;
	return (dest);
}

// int	main(void)
// {
// 	char str1[] = "123456789";
// 	char str2[] = "123456789";
// 	char str3[] = "123456789";
// 	char str4[] = "123456789";
//
// 	memcpy(str1 + 3, str2 + 4, ft_strlen(str1));
// 	ft_memcpy(str3 + 3, str4 + 4, ft_strlen(str3));
//
// 	// memcpy(str1 + 3, str2, 4);
// 	// ft_memcpy(str3 + 3, str4, 4);
//
// 	printf("%s\n", (char *)str1);
// 	printf("%s\n", (char *)str3);
// 	return (0);
// }
//
// int	main(void)
// {
// 	char *str1 = NULL;
// 	// char str2[] = "123456789";

// 	// ft_memcpy(((void*)0), ((void*)0), 3);
// 	ft_memcpy(NULL, NULL, 3);
// 	// ft_memcpy(str1, str2 + 4, 4);
// 	printf("%s\n", (char *)str1);
// 	return (0);
// }
