/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 14:17:05 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/24 20:45:41 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

// int	main(void)
// {
// 	char	*ptr = "Hello World!";
// 	char	*substr = ft_substr(ptr, 0, 7);

// 	printf("%s\n", substr);
// 	free(substr);

// 	// char	*s = ft_substr("tripouille", 100, 1);
// 	// printf("%p\n", s);
// 	// free(s);
// 	return (0);
// }

// char	*ft_substr(const char *s, unsigned int start, size_t len)
// {
// 	char	*ret;

// 	if (!s)
// 		return (0);
// 	if (ft_strlen(s) <= start)
// 		len = 0;
// 	else if (ft_strlen(s + start) < len)
// 		len = ft_strlen(s + start);
// 	ret = malloc(sizeof(char) * (len + 1));
// 	if (!ret)
// 		return (0);
// 	// ft_strlcpy(ret, s + start, len + 1);
// }