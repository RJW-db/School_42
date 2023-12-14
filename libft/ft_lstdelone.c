/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 23:33:10 by rjw           #+#    #+#                 */
/*   Updated: 2023/10/30 13:41:34 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

// static void	ft_del(void *ptr)
// {
// 	if (ptr)
// 		free(ptr);
// }

// int	main(void)
// {
// 	t_list *node = ft_lstnew(ft_strdup("some value"));
// 	node->next = ft_lstnew(ft_strdup("more values"));
// 	printf("%s\n", (char *)node->content);
// 	printf("%s\n", (char *)node->next->content);

// 	ft_lstdelone(node->next, ft_del);
// 	// printf("%s\n", (char *)node->content);
// 	// printf("%s\n", (char *)node->next->content);
// }
