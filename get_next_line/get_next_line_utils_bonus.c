/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/24 14:29:21 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/12/05 18:56:00 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_str(char *str)
{
	free(str);
	return (NULL);
}

size_t	str_len(const char *str)
{
	size_t	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n] && str[n] != '\n')
		n++;
	if (str[n] == '\n')
		return (n + 1);
	return (n);
}

int	cpy(char *dest, const char *src, bool *nl_check)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (dest[i] == '\n')
		{
			dest[++i] = '\0';
			*nl_check = true;
			return (i);
		}
		i++;
	}
	dest[i] = '\0';
	*nl_check = false;
	return (i);
}
