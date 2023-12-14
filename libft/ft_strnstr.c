/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:55:43 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:55:43 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		j;

	if (len == 0 && *little)
		return (0);
	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		j = 0;
		while (big[j] == little[j] && big[j] && little[j] && len - j)
			j++;
		if (little[j] == '\0')
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*haystack = "Foo Bars Bazs";
// 	const char	*needle = "Baz";
// 	char *ptr;
// 	char *ptr2;
// 	ptr = ft_strnstr(haystack, needle, 2);
// 		printf("%s\n", ptr);
// 	ptr2 = strnstr(haystack, needle, 2);
// 		printf("%s", ptr2);
// 	return (0);
//	//	-lbsd
// }
