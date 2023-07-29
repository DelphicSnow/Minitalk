/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:52:13 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/31 13:45:24 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	i = 0;
	if (start >= slen)
		len = 0;
	else if (len >= slen)
		len = slen - start;
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	while (i < len)
		p[i++] = *(s + start++);
	return (p);
}
