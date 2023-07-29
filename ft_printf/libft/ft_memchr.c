/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:45:48 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/15 17:07:05 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*sm;
	size_t		i;

	i = 0;
	sm = (const char *)s;
	while (i < n)
	{
		if (sm[i] == c)
			return ((void *)&sm[i]);
		i++;
	}
	return ((void *)0);
}
