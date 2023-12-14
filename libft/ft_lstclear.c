/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 00:15:08 by rjw           #+#    #+#                 */
/*   Updated: 2023/10/27 21:23:59 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (*lst && del)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
		*lst = NULL;
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

// 	ft_lstclear(&node, ft_del);
// 	// printf("%s\n", (char *)temp->content);
// 	// printf("%s\n", (char *)temp->node->content);
// }