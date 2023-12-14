/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 14:57:00 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 19:42:49 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// int	main(void)
// {
// 	int	i = 0;
// 	t_list *head = NULL;

// 	while (i < 4)
// 	{
// 		ft_lstadd_front(&head, ft_lstnew(""));
// 		i++;
// 	}
// 	printf("%d\n", ft_lstsize(head));

// 	return (1);
// }
