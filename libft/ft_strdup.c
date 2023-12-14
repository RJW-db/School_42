/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:45:15 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:45:15 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

// int	main(void)
// {
// 	char	*string = "Hello World!";
// 	char	*ptr = ft_strdup(string);

// 	if (ptr != NULL)
// 	{
// 		printf("%s\n", ptr);
// 		free(ptr);
// 	}
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (0);
// }
