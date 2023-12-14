/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:39:07 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:39:07 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr;
	int		flag;

	flag = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		flag = -1;
	}
	if (n / 10)
		ft_putnbr_fd(n / 10 * flag, fd);
	nbr = '0' + n % 10 * flag;
	ft_putchar_fd(nbr, fd);
}

// int	main(void)
// {
// 	int	i = -2147483648;
// 	int fd = open("info.txt", O_WRONLY);

// 	ft_putnbr_fd(i, fd);
// 	return (0);
// }
