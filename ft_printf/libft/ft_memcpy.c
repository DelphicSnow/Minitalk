/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:14:59 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/29 15:39:18 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdest;

	if (dest == NULL && src == NULL)
		return (NULL);
	csrc = (char *)src;
	cdest = (char *)dest;
	while (n > 0)
	{
		*cdest++ = *csrc++;
		n--;
	}
	return (dest);
}
