/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 21:20:44 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/12/07 01:27:13 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libext.h"
#define MARKUP "\033[35m\\"
#define M_UP_SIZE 6
#define MARKDOWN "\033[0m"
#define M_DOWN_SIZE 4
#define BACKPRINT "\a\b\t\n\v\f\r\177"

static int	ft_cpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		// printf("(i = %d - <%c>) ", i, src[i]);
		dest[i] = ((unsigned char *)src)[i];
		i++;
	}
	// printf("(i = %d) ", i);
	return (--i);
}

static int	ft_putchar_octal(const int c)
{
	char	esc[15];

	ft_cpy(esc, MARKUP, M_UP_SIZE);
	esc[7] = ((c >> 6) & 7) + '0';
	esc[8] = ((c >> 3) & 7) + '0';
	esc[9] = ((c >> 0) & 7) + '0';
	ft_cpy(esc + 10, MARKDOWN, M_DOWN_SIZE);
	return (write(1, esc, 15));
}

/**
 * @brief returns len = 13 || len  = 15 when it's DEL
*/
static int	ft_putchar_back(const int c)
{
	const char	*except = "abtnvfrD0";
	int			len;
	int			i;
	char		stash[15];

	len = 0;
	len += ft_cpy(stash, MARKUP, M_UP_SIZE);
	// printf("\n\n\nstash: %s\n\nh\n", stash);
	i = 0;
	if (c == '\177')
		len += ft_cpy(stash + len, "DEL", 3);
	else
		while (BACKPRINT[i])
			if (c == BACKPRINT[i++])
				len += ft_cpy(stash + len, &except[i - 1], 1);
	len += ft_cpy(stash + len, MARKDOWN, M_DOWN_SIZE);
	// printf("len = %d\n", len);
		write(1, &stash[5], 1);
	// write(1, &stash[6], 1);
	// write(1, &stash[7], 1);
	return (write(1, stash, len));
}

int	ft_writing(const char *str, int n)
{
	const int	strlen = ft_strlen(str);
	int			len;
	int			i;
	// char		tmp[100];

	len = 0;
	if (n == 0)
		n = strlen;
	if (n == -1)
		n = strlen + 1;
	i = 0;
	// ft_putstr_fd("here\n", 1);
	while (i < n)
	{
		if (i >= strlen)
			len += write(1, "\033[2m", 4);
		if (ft_strchr(BACKPRINT, str[i]))
			len += ft_putchar_back(str[i]);
		else if (!ft_isprint(str[i]))
			len += ft_putchar_octal(str[i]);
		else
			len += write(1, &str[i], 1);
		i++;
	}
	// printf("(markdown %lu)", sizeof(MARKUP));
	return (len);
}

// //	cc -Wall -Wextra -Werror ft_writing.c ft_strlen.c ft_strchr.c ft_isprint.c zzzz.c ft_putstr_fd.c && ./a.out
// int	main(void)
// {
// 	ft_writing("check\nthis\nline", 0);
// 	// int i = ft_writing("check\nthis\nline", 0);
// 	// int i = ft_writing_fd("\033", 0,);
// 	// usleep(5000000);
// 	// printf("\ni = %d\n", i);
// 	return (1);
// }
// //	cc -Wall -Wextra -Werror ft_writing_fd.c ft_writing.c ft_strlen.c ft_strchr.c ft_isprint.c zzzz.c ft_putstr_fd.c && ./a.out