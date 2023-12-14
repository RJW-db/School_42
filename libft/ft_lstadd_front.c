/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 01:38:10 by rjw           #+#    #+#                 */
/*   Updated: 2023/10/27 21:21:53 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	t_list *new_node = malloc(sizeof(t_list));
// 	if (!new_node)
// 	{
// 		fprintf(stderr, "Memory allocation error\n");
// 		return (1);
// 	}
// 	new_node->content = "New Node";
// 	new_node->next = NULL;
// //
// 	t_list *head = NULL;
// //
// 	ft_lstadd_front(&head, new_node);
// //
// 	t_list *current = head;
// 	while (current != NULL)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// //
// 	while (head != NULL)
// 	{
// 		t_list *temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// 	return (0);
// }
