/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   markup.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 21:54:57 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/12/13 21:29:33 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libext.h"
/**
 * @brief The last argument must be 0 (zero) for termination.
*/
void	markup(char *str, ...)
{
	va_list	style;
	int		num_styles;
	int		minus_check;

	num_styles = 0;
	va_start(style, str);
	while (va_arg(style, int) != 0)
		num_styles++;
	va_end(style);
	va_start(style, str);
	if (num_styles == 0)
		printf("%s", str);
	else if (num_styles > 0)
	{
		minus_check = va_arg(style, int);
		// if (minus_check == -1 && printf("\033[45m%s\033[0m", str))
		// 	return ;
		printf("\033[%d", minus_check);
		while (--num_styles)
			printf(";%d", va_arg(style, int));
		printf("m%s\033[0m", str);
	}
	va_end(style);
}
