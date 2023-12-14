/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:49:13 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/24 19:21:39 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*s1)
		*(p++) = *(s1++);
	while (*s2)
		*(p++) = *(s2++);
	*p = '\0';
	return (p - len);
}

// int	main(void)
// {
// 	char	line1[] = "Hello ";
// 	char	line2[] = "World!";
// 	char	*strjoin = ft_strjoin(line1, line2);

// 	printf("%s\n", strjoin);
// 	free(strjoin);

// 	return (0);
// }
