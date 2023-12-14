/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/24 14:22:32 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/12/04 16:55:16 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*str_merge(const char *nl, char *buf, bool *nl_check, int rd)
{
	char		*p;
	size_t		len;

	buf[rd] = '\0';
	if (buf[0] == '\0')
		return ((char *)nl);
	len = str_len(nl) + str_len(buf);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (free_str((char *)nl));
	len = cpy(p, nl, nl_check);
	len = cpy(p + len, buf, nl_check);
	while (*(buf + len) != '\0')
	{
		*buf = *(buf + len);
		buf++;
	}
	*buf = '\0';
	free((char *)nl);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	buff[MAX_FDS][BUFFER_SIZE + 1];
	char		*new_line;
	int			rd;
	bool		nl_check;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = NULL;
	rd = BUFFER_SIZE;
	new_line = str_merge(new_line, buff[fd], &nl_check, BUFFER_SIZE);
	if (new_line && nl_check == true)
		return (new_line);
	while (rd == BUFFER_SIZE)
	{
		rd = read(fd, buff[fd], BUFFER_SIZE);
		if (rd >= 0)
			new_line = str_merge(new_line, buff[fd], &nl_check, rd);
		if (rd < 0 || !new_line || *new_line == '\0')
			return (free_str(new_line));
		if (nl_check == true)
			return (new_line);
	}
	return (new_line);
}
