/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:39:12 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/27 17:14:37 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**fucknorminette(char const *s, char **arr, char c, int j)
{
	int	len;
	int	i;

	i = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j] != 0)
		{
			len = 0;
			while (s[j + len] != c && s[j + len] != 0)
				len++;
			arr[i] = ft_calloc(sizeof(char), len +1);
			ft_memcpy(arr[i], &s[j], len);
			i++;
			j = j + len;
		}
	}
	arr[i] = 0;
	return (arr);
}

int	word_counter(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != 0)
	{
		while (*s == c)
			s++;
		while (*s != c && *s != 0)
		{
			s++;
			if (*s == '\0' || *s == c)
				count++;
		}
	}
	count ++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		j;

	if (s == 0)
		return (0);
	j = 0;
	arr = (char **)malloc(sizeof(char *) * word_counter(s, c));
	if (!arr)
		return (0);
	fucknorminette(s, arr, c, j);
	return (arr);
}
