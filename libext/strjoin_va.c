/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strjoin_va.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/09 03:20:33 by rjw           #+#    #+#                 */
/*   Updated: 2023/12/13 03:04:39 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libext.h"

static void	append_to_string(char *dest, const char *src, size_t *index)
{
	while (*src != '\0')
	{
		dest[(*index)++] = *src++;
	}
}

static size_t	calculate_total_length(const char *fmt, va_list args)
{
	size_t	len;
	char	*str;

	len = ft_strlen(fmt);
	str = va_arg(args, char *);
	while (1)
	{
		len += ft_strlen(str);
		str = va_arg(args, char *);
		if (str == NULL)
		{
			break ;
		}
	}
	return (len);
}

static char	*concat_str(const char *fmt, va_list args, size_t total_length)
{
	char		*new_line;
	size_t		index;
	const char	*str;

	new_line = (char *)malloc((total_length + 1) * sizeof(char));
	if (new_line == NULL)
	{
		return (NULL);
	}
	new_line[total_length] = '\0';
	index = 0;
	append_to_string(new_line, fmt, &index);
	while (1)
	{
		str = va_arg(args, const char *);
		if (str == NULL)
		{
			break ;
		}
		append_to_string(new_line, str, &index);
	}
	return (new_line);
}
/**
 * @brief Last argument must be NULL
*/
char	*strjoin_va(const char *fmt, ...)
{
	va_list	va;
	char	*new_line;
	size_t	total_length;

	va_start(va, fmt);
	total_length = calculate_total_length(fmt, va);
	va_end(va);
	va_start(va, fmt);
	new_line = concat_str(fmt, va, total_length);
	va_end(va);
	return (new_line);
}

// int main(void) {
// 	const char *str = "Get ";
// 	const char *midone = "to ";
// 	const char *midtwo = "the ";
// 	const char *end = "chopper!";
// 	char *new_line;

// 	new_line = strjoin_va(str, midone, midtwo, end, NULL);
// 	if (new_line != NULL) {
// 		printf("%s\n", new_line);
// 		free(new_line);
// 	} else {
// 		// Handle allocation failure
// 		fprintf(stderr, "Memory allocation failed\n");
// 		return 1;
// 	}

// 	return 0;
// }
