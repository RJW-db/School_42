/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 13:45:29 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/27 19:40:36 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list) * 1);
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

// int	main(void)
// {
// 	int		*data;
// 	t_list	*node;

// 	data = malloc(sizeof(t_list));
// 	if (!data)
// 		return (0);
// 	*data = 2023;
// 	node = ft_lstnew(data);
// 	if (node != NULL)
// 	{
// 		printf("%d\n", *(int *)node->content);
// 		free(node->content);
// 		free(node);
// 	}
// }
