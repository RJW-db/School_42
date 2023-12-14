/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writing_fd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 21:20:44 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/12/07 01:27:27 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libext.h"
#define MARKUP "\033[35m\\"
#define M_UP_SIZE 7
#define MARKDOWN "\033[0m"
#define M_DOWN_SIZE 5
#define BACKPRINT "\a\b\t\n\v\f\r\177"

static int	ft_int_putstr_fd(char *s, int fd)
{
	// return (write(fd, s, ft_strlen(s)));

	if (s || fd)
		return (0);
	return (0);
}

static int	ft_cpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (i);
}

static int	ft_putchar_octal(const int c, int fd)
{
	char	esc[15];

	ft_cpy(esc, MARKUP, M_UP_SIZE);
	esc[7] = ((c >> 6) & 7) + '0';
	esc[8] = ((c >> 3) & 7) + '0';
	esc[9] = ((c >> 0) & 7) + '0';
	ft_cpy(esc + 10, MARKDOWN, M_DOWN_SIZE);
	return (ft_int_putstr_fd(esc, fd));
}

/**
 * @brief returns len = 13 || len  = 15 when it's DEL
*/
static int	ft_putchar_back(const int c, int fd)
{
	const char	*except = "abtnvfrD0";
	int			len;
	int			i;
	char		stash[15];

	len = 0;
	len += ft_cpy(stash, MARKUP, M_UP_SIZE);
	i = 0;
	if (c == '\177')
		len += ft_cpy(stash + len, "DEL", 3);
	else
		while (BACKPRINT[i])
			if (c == BACKPRINT[i++])
				len += ft_cpy(stash + len, &except[i - 1], 1);
	len += ft_cpy(stash + len, MARKDOWN, M_DOWN_SIZE);
	// printf("len = %d\n", len);
	// write(1, stash, 13);
	write(1, &stash[5], 1);
	write(1, &stash[7], 1);
	return (ft_int_putstr_fd(stash, fd));
}

int	ft_writing_fd(const char *str, int n, int fd)
{
	const int	strlen = ft_strlen(str);
	int			len;
	int			i;
	// char		tmp[100];
// printf("%s\n", str);
// printf("strlen : %d", strlen);
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
			len += ft_int_putstr_fd("\033[2m", fd);
		if (ft_strchr(BACKPRINT, str[i]))
			len += ft_putchar_back(str[i], fd);
		else if (!ft_isprint(str[i]))
			len += ft_putchar_octal(str[i], fd);
		else
			len += write(fd, &str[i], 1);
		i++;
	}
	return (len);
}

// //	cc -Wall -Wextra -Werror ft_writing_fd.c ft_strlen.c ft_strchr.c ft_isprint.c zzzz.c ft_putstr_fd.c && ./a.out
// int	main(void)
// {
// 	int		fd = open("info.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
// 	ft_writing_fd("\033does this work", 0, fd);
// 	return (1);
// }
// //	cc -Wall -Wextra -Werror ft_writing_fd.c ft_writing.c ft_strlen.c ft_strchr.c ft_isprint.c zzzz.c ft_putstr_fd.c && ./a.out
