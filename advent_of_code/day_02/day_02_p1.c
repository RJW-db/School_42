/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day_02_p1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 12:55:55 by rjw           #+#    #+#                 */
/*   Updated: 2023/12/14 15:26:22 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../library/archive.h"

int	check_numbers_of_cubes(char c, int *j)
{
	const int	red = 12;
	const int	green = 13;
	const int	blue = 14;

	if (c == 'r' && *j <= red)
	{
		return (*j = 3);
	}
	else if (c == 'g' && *j <= green)
	{
		return (*j = 5);
	}
	else if (c == 'b' && *j <= blue)
	{
		return (*j = 4);
	}
	return (0);
}

int	numbers(char *nl)
{
	int		i;
	int		j;
	char	values[4];

	i = 0;
	j = 0;
	while (nl[i] != '\n')
	{
		ft_bzero(values, 4);
		while (ft_isdigit(nl[i]) == 0 && nl[i] != '\n' && nl[i] != '\0')
			i++;
		if (nl[i] == '\n' || nl[i] == '\0')
			return (1);
		while (ft_isdigit(nl[i]) != 0)
			values[j++] = nl[i++];
		j = ft_atoi(values);
		i++;
		if (check_numbers_of_cubes(nl[i], &j) == 0)
			return (0);
		i += j;
		j = 0;
	}
	return (1);
}

static void	total_sum(int fd)
{
	char		*new_line;
	int			i;
	int			total;

	i = 1;
	total = 0;
	new_line = get_next_line(fd);
	if (new_line == NULL)
		return ;
	while (new_line != NULL)
	{
		if (numbers(new_line + 8) == 1)
			total += i;
		free(new_line);
		new_line = get_next_line(fd);
		i++;
	}
	printf("part 1: %d\n\n", total);
	return ;
}

/**
 * @brief printf must be replaced with ft_printf
*/
int	main(int argc, char **argv)
{
	int		fd;
	clock_t	start_time;

	if (argc != 2)
		return (1);
	print_full_width('-');
	start_time = clock();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error opening file", STDOUT_FILENO), 1);
	total_sum(fd);
	close(fd);
	exe_time(start_time);
	return (0);
}
