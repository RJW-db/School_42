/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_header.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/09 03:40:22 by rjw           #+#    #+#                 */
/*   Updated: 2023/12/13 04:32:13 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libext.h"

#define START_STR "#ifndef ARCHIVE_H\n# define ARCHIVE_H\n\n# include \
<stdio.h>\n# include <fcntl.h>\n"
#define INCL "# include \""
#define END_STR "\n#endif"

static void	*free_str(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

static char	*create_header(int argc, char **argv)
{
	char		*nl;
	char		*tmp;
	int			i;

	if (argc == 1)
		return (ft_strjoin(START_STR, END_STR));
	nl = strjoin_va(START_STR, INCL, argv[1], "\"\n", NULL);
	if (nl == NULL)
	{
		return (NULL);
	}
	i = 2;
	while (i < argc)
	{
		tmp = strjoin_va(nl, INCL, argv[i], "\"\n", NULL);
		free_str(nl);
		if (tmp == NULL)
		{
			return (NULL);
		}
		nl = tmp;
		i++;
	}
	return (strjoin_free(nl, END_STR));
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*new_line;

	if (argc < 2)
	{
		return (1);
	}
	fd = open("archive.h", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
	{
		ft_putendl_fd("Error opening file", STDOUT_FILENO);
		return (1);
	}
	new_line = create_header(argc, argv);
	if (new_line == NULL)
		return (1);
	ft_putstr_fd(new_line, fd);
	free(new_line);
	close(fd);
	return (0);
}
