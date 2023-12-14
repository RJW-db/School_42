/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day_one.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 15:46:13 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/12/14 01:59:02 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../library/archive.h"

#define DIGITS "0123456789"
#define DIGITS_FIRST_LETTER "zotfsen"
#define PART_ONE false
#define PART_TWO true
#define FRONT true
#define BACK false

static void	front_or_back_digit(char nl, char *str, bool f_or_b)
{
	int	i;

	i = 0;
	while (DIGITS[i] != '\0')
	{
		if (ft_strchr(DIGITS, nl) != NULL)
		{
			if (f_or_b == true)
				str[0] = nl;
			else
				str[1] = nl;
			return ;
		}
		i++;
	}
}

static void	front_or_back_word(char *nl, char *str, bool f_or_b)
{
	const char	*words[] = {"zero", "one", "two", "three", "four", \
							"five", "six", "seven", "eight", "nine"};
	char		*tmp;
	int			j;
	int			i;

	i = 0;
	tmp = ft_strchr(DIGITS_FIRST_LETTER, nl[i]);
	if (tmp == NULL || tmp[0] == '\0')
		return ;
	while (i < 10)
	{
		j = 0;
		while (words[i][j] != '\0' && words[i][j] == nl[j])
			j++;
		if (words[i][j] == '\0')
		{
			if (f_or_b == true)
				str[0] = DIGITS[i];
			else
				str[1] = DIGITS[i];
			return ;
		}
		i++;
	}
}

static void	find_nbr(char *new_line, char *two_numbers, int i, bool p2)
{
	int	j;

	j = ft_strlen(new_line) - 1;
	while (new_line[i] != '\0')
	{
		if (ft_isdigit(new_line[i]) > 0 && two_numbers[0] == '\0')
		{
			front_or_back_digit(new_line[i], two_numbers, FRONT);
		}
		else if (two_numbers[0] == '\0' && p2 == true)
			front_or_back_word(new_line + i, two_numbers, FRONT);
		if (ft_isdigit(new_line[j]) > 0 && two_numbers[1] == '\0')
		{
			front_or_back_digit(new_line[j], two_numbers, BACK);
		}
		else if (two_numbers[1] == '\0' && p2 == true)
			front_or_back_word(new_line + j - 2, two_numbers, BACK);
		if (two_numbers[0] != '\0' && two_numbers[1] != '\0')
			return ;
		i++;
		j--;
	}
}

static int	total_sum(int fd, bool p2)
{
	char	*new_line;
	char	two_numbers[3];
	int		total_length;
	int		i;

	ft_bzero(two_numbers, 3);
	i = 0;
	total_length = 0;
	new_line = get_next_line(fd);
	while (new_line != NULL)
	{
		find_nbr(new_line, two_numbers, i, p2);
		free(new_line);
		total_length += ft_atoi(two_numbers);
		ft_bzero(two_numbers, 3);
		new_line = get_next_line(fd);
	}
	return (total_length);
}

/**
 * @brief printf must be replaced with ft_printf
*/
int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	clock_t	start_time;

	if (argc != 2)
		return (1);
	print_full_width('-');
	start_time = clock();
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		return (ft_putendl_fd("Error opening file", STDOUT_FILENO), 1);
	printf("part1:\t%i\n", total_sum(fd1, PART_ONE));
	printf("part2:\t%i\n", total_sum(fd2, PART_TWO));
	close(fd1);
	close(fd2);
	exe_time(start_time);
	return (0);
}
