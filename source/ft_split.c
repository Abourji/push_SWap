/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:16:57 by adbourji          #+#    #+#             */
/*   Updated: 2024/05/14 23:59:48 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**free_memory(char **str)
{
	while (*str)
	{
		free(*str);
		str--;
	}
	free(str);
	return (0);
}

char	**split_words(char **ptr, const char *str, char del)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == del)
			i++;
		j = i;
		while (str[i] && str[i] != del)
			i++;
		if (i > j)
		{
			ptr[k++] = ft_substr(str, j, i - j);
			if (!ptr[k - 1])
			{
				free_memory(ptr);
				return (NULL);
			}
		}
	}
	ptr[k] = NULL;
	return (ptr);
}

char	**ft_split(char const *str, char del)
{
	char	**ptr;
	int		i;

	if (!str)
		return (NULL);
	i = ft_count_words((char *)str, del);
	ptr = (char **)malloc((i + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr[i] = NULL;
	ptr = split_words(ptr, str, del);
	if (!ptr)
	{
		free_memory(ptr);
		return (NULL);
	}
	return (ptr);
}
