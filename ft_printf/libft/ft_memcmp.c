/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:08:06 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/29 15:54:07 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1m;
	const unsigned char	*s2m;
	size_t				i;

	s1m = (const unsigned char *)s1;
	s2m = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1m[i] == s2m[i] && i < (n - 1))
		i++;
	return (s1m[i] - s2m[i]);
}
