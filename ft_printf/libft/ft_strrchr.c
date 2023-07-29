/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:42:55 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/15 16:44:43 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*p;

	p = (char *)s;
	index = ft_strlen(p);
	while (index >= 0)
	{
		if (p[index] == c)
			return (p + index);
		index --;
	}
	return (NULL);
}
