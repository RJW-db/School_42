/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 21:21:52 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/30 14:21:13 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*tmp;

	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		tmp = f(lst->content);
		new_node = ft_lstnew(tmp);
		if (new_node == NULL)
		{
			del(tmp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_node);
	}
	return (new_lst);
}

// static void	ft_del(void *ptr)
// {
// 	if (ptr)
// 		free(ptr);
// }

// int	main(void)
// {
// 	t_list *head = ft_lstnew("G");
// 	t_list *cpy_head = head;
// 	char *ptr = "ot it working";
// 	while (*ptr)
// 	{
// 		head->next = ft_lstnew(ptr);
// 		head = head->next;
// 		ptr++;
// 	}
// 	t_list *retrieved_list = ft_lstmap(cpy_head, (void *)ft_strdup, ft_del);
// 	while (retrieved_list)
// 	{
// 		printf("%c", *(char *)retrieved_list->content);

// 		t_list *tmp_head = cpy_head->next;
// 		free(cpy_head);
// 		cpy_head = tmp_head;

// 		t_list *tmp = retrieved_list->next;
// 		if (retrieved_list->content != NULL)
// 			free(retrieved_list->content);
// 		free(retrieved_list);
// 		retrieved_list = tmp;
// 	}

// 	printf("\n");
// 	return (0);
// }
