/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:54:02 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:54:02 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// static char	ft_tolowertwo(unsigned int n, char c)
// {
// 	if (n % 2 == 0 && c >= 65 && c <= 90)
// 		return (c + 32);
// 	return (c);
// }

// int	main(void)
// {
// 	char *str = "SOMETHING";
// 	char *modified = ft_strmapi(str, ft_tolowertwo);

// 	if (modified != NULL)
// 	{
// 		printf("%s\n", modified);
// 		free(modified);
// 	}
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (1);
// }
