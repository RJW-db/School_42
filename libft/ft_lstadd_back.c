/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 18:42:09 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 21:20:44 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (*lst)
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
	else
		*lst = new;
}

// int	main(void)
// {
// 	t_list	*new_node = ft_lstnew("XXX");
// 	t_list	*head = ft_lstnew("First node");
// 	t_list	*cpy_head = head;
// 	t_list	*next_node;
// 	char	*ptr = "abcdefg";

// 	while (*ptr)
// 	{
// 		head->next = ft_lstnew(ptr);
// 		head = head->next;
// 		ptr++;
// 	}
// 	ft_lstadd_back(&head, new_node);

// 	printf("print first node: %s\n\n", (char *)cpy_head->content);
// 	printf("print last node: %s\n\n", (char *)head->next->content);

// 	while (cpy_head != NULL)
// 	{
// 	    printf("%c\n", *(char *)cpy_head->content);
// 		next_node = cpy_head->next;
// 		free(cpy_head);
// 	    cpy_head = next_node;
// 	}
//     return (0);
// }
