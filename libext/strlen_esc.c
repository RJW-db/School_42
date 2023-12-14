/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen_esc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 21:07:06 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/12/07 01:26:40 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libext.h"

size_t	strlen_esc(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] > 0 && s[i] <= 127)
		i++;
	return (i);
}
