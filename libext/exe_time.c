/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exe_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/02 02:40:08 by rjw           #+#    #+#                 */
/*   Updated: 2023/12/13 19:10:33 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libext.h"

static void	reverse(char *str, int len)
{
	int		start;
	char	temp;

	start = 0;
	len -= 1;
	while (start < len)
	{
		temp = str[start];
		str[start] = str[len];
		str[len] = temp;
		start++;
		len--;
	}
}

static void	convert_decimal(double decimal, char *buff, int precision, int i)
{
	int	j;

	j = 0;
	while (j < precision)
	{
		decimal *= 10;
		buff[i] = (int)decimal + '0';
		decimal -= (int)decimal;
		i++;
		j++;
	}
	buff[i] = '\n';
	buff[++i] = '\0';
}

static char	*ftoa(double num, char *buff, int precision)
{
	int		whole_part;
	double	decimal;
	int		i;

	whole_part = (int)num;
	i = 0;
	while (whole_part != 0)
	{
		buff[i++] = (whole_part % 10) + '0';
		whole_part /= 10;
	}
	if (i == 0)
		buff[i++] = '0';
	reverse(buff, i);
	buff[i++] = '.';
	decimal = num - (int)num;
	convert_decimal(decimal, buff, precision, i);
	return (buff);
}

/**
 * @brief #include <time.h>  <----->  
 * clock_t start_time = clock();
 */
void	exe_time(clock_t start_time)
{
	clock_t	end_time;
	double	cpu_time_used;
	int		length;
	char	buff[21];

	end_time = clock();
	cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	ftoa(cpu_time_used, buff, 6);
	length = 0;
	while (buff[length] != '\0')
		++length;
	write(1, "Execution time:\t", 16);
	write(STDOUT_FILENO, buff, length);
}

// int	main(void)
// {
// 	clock_t start_time = clock();
// 	int i = 0;
// 	while (i < INT_MAX)
// 		i++;
// 	while (i < INT_MAX)
// 		i++;
// 	while (i < INT_MAX)
// 		i++;
// 	while (i < INT_MAX)
// 		i++;
// 	while (i < INT_MAX)
// 		i++;
// 	while (i < INT_MAX)
// 		i++;
// 	while (i < INT_MAX)
// 		i++;
// 	while (i < INT_MAX)
// 		i++;
// 	while (i < INT_MAX)
// 		i++;
//     exe_time(start_time);
//     return (0);
// }
