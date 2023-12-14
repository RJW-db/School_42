/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 17:25:19 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/30 13:54:22 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list *head = ft_lstnew("First node");
// 	t_list *cpy_head = head;
// 	t_list *tmp = NULL;
// 	char *ptr = "abcdefg";
// 	while (*ptr)
// 	{
// 		head->next = ft_lstnew(ptr);
// 		head = head->next;
// 		ptr++;
// 	}
// 	printf("%s\n", (char *)ft_lstlast(cpy_head)->content);
// 	while (cpy_head)
// 	{
// 		printf("%s\n", (char *)cpy_head->content);
// 		tmp = cpy_head->next;
// 		free(cpy_head);
// 		cpy_head = tmp;
// 	}
// 	return (0);
// }
