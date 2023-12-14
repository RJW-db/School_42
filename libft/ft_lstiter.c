/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 00:31:39 by rjw           #+#    #+#                 */
/*   Updated: 2023/10/30 13:41:22 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// static void	ft_print(void *ptr)
// {
// 	printf("%c\n", *(char *)ptr);
// }

// int	main(void)
// {
// 	t_list	*head = ft_lstnew("First node");
// 	t_list	*cpy_head = head;
// 	t_list	*tmp = NULL;
// 	char	*ptr = "abcdefg";

// 	while (*ptr)
// 	{
// 		head->next = ft_lstnew(ptr);
// 		head = head->next;
// 		ptr++;
// 	}
// 	ft_lstiter(cpy_head, ft_print);
// 	printf("\n");
// 	while (cpy_head)
// 	{
// 		printf("%s\n", (char *)cpy_head->content);
// 		tmp = cpy_head->next;
// 		free(cpy_head);
// 		cpy_head = tmp;
// 	}
// 	return (0);
// }
