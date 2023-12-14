/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:28:01 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/10/13 13:28:01 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	t;
	void	*ptr;

	t = nmemb * size;
	if (nmemb != 0 && size != 0 && t / nmemb != size)
		return (NULL);
	ptr = malloc(t);
	if (ptr != NULL)
		ft_memset(ptr, 0, t);
	return (ptr);
}

// int	main(void)
// {
// 	// int* arr = (int*)ft_calloc(10, sizeof(int));
// 	char* arr = (char*)ft_calloc(10, sizeof(char));
// 	// void* arr = ft_calloc(10, sizeof(int));
// 			// printf("%d ", ((int *)arr)[i]);
// 	if (arr != NULL)
// 	{
// 		for (size_t i = 0; i < 10; ++i)
// 			printf("%d ", arr[i]); 
// 		free(arr);
// 	}
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (0);
// }
