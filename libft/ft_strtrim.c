/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:57:17 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 20:33:54 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trim(char n, const char *str)
{
	while (*str)
		if (*str++ == n)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_trim(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_trim(s1[end - 1], set) == 1)
		end--;
	trimmed = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}

// int	main(void)
// {
// 	char	line1[] = "rtsHello this str is awesome! rs";
// 	char	line2[] = "str";
// 	char	*strtrim = ft_strtrim(line1, line2);

// 	printf("%s\n", strtrim);
// 	free(strtrim);

// 	return (0);
// }
