/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:20:45 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/29 16:14:04 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	offset;
	size_t	src_index;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	offset = dst_len;
	src_index = 0;
	if (size == 0 || size <= dst_len)
		return (size + src_len);
	while (src[src_index] != '\0' && (offset < size - 1))
	{
		dst[offset] = src[src_index];
		offset++;
		src_index++;
	}
	dst[offset] = '\0';
	return (dst_len + src_len);
}
