/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strjoin_free.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/09 03:10:25 by rjw           #+#    #+#                 */
/*   Updated: 2023/12/09 03:10:53 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libext.h"

char	*strjoin_free(const char *s1, const char *s2)
{
	char	*p;
	size_t	len;
	char	*s3;

	if (!s2)
		return (NULL);
	s3 = (char *)s1;
	len = 0;
	if (s3 != NULL)
		len = ft_strlen(s3);
	len += ft_strlen(s2);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*s3)
		*(p++) = *(s3++);
	while (*s2)
		*(p++) = *(s2++);
	*p = '\0';
	if (s3 != NULL)
		free((char *)s1);
	return (p - len);
}
