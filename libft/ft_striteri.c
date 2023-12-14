/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:45:29 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 17:05:43 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// static void	ft_tolowertwo(unsigned int n, char *c)
// {
// 	if (n % 2 == 0 && c[0] >= 65 && *c <= 90)
// 		printf("%c", *c + 32);
// 	else
// 		printf("%c", *c);
// }

// int	main(void)
// {
// 	char	*s = "SOMETHING";
// 	ft_striteri(s, ft_tolowertwo);
// 	return (0);
// }
