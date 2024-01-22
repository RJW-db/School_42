/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 14:42:32 by rde-brui      #+#    #+#                 */
/*   Updated: 2024/01/20 01:52:10 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cpy(char *dst, const char *src)
{
	short	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

int	cpy_num(char *dst, const char *src, int num)
{
	short	i;

	i = 0;
	while (src[i] != '\0' && num > 0)
	{
		dst[i] = src[i];
		i++;
		num--;
	}
	return (i);
}

int	cpy_number(char *str, const char c, int n)
{
	short	i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (i);
}

size_t	str_len(const char *s)
{
	short	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	signed_decimal_base(char *str, int n)
{
	const char	store[12] = {0};
	const char	*base = "0123456789";
	char		*number;
	long		negative;

	if (n == 0)
	{
		str[0] = '0';
		return (1);
	}
	negative = n;
	if (negative < 0)
		negative *= -1;
	number = &((char *)store)[11];
	while (negative != 0)
	{
		*(--number) = base[negative % 10];
		negative /= 10;
	}
	if (n < 0)
		*(--number) = '-';
	return (cpy(str, number));
}
