/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:43:49 by rde-brui      #+#    #+#                 */
/*   Updated: 2023/11/10 18:06:25 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

static int	ft_malloc(const char *start, const char *end, char **r)
{
	int		len;

	len = end - start;
	*r = (char *)malloc((len + 1) * sizeof(char));
	if (!*r)
		return (0);
	if (!ft_strlcpy(*r, start, len + 1))
		return (0);
	return (1);
}

static int	ft_words(const char *s, char c, char **res, int *w_index)
{
	char	*start;

	start = (char *)s;
	while (*s)
	{
		if (*s != c)
			s++;
		else
		{
			if (start != s && ft_malloc(start, s, &res[(*w_index)++]) == 0)
				return (0);
			start = (char *)++s;
		}
	}
	if (start != s && ft_malloc(start, s, &res[(*w_index)++]) == 0)
		return (0);
	*(res + *w_index) = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		w_index;
	int		i;

	result = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	w_index = 0;
	if (ft_words(s, c, result, &w_index) == 0)
	{
		i = 0;
		while (w_index > i)
			free(result[i++]);
		free(result);
		return (NULL);
	}
	return (result);
}

// int	main(void)
// {
// 	const char *input_string = "Hello,World,This,Is,An,Example,";
// 	char delimiter = ',';

// 	char **result = ft_split(input_string, delimiter);

// 	if (result)
// 	{
// 		size_t i = 0;
// 		while (result[i]) {
// 			printf("%s\n", result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (0);
// }
