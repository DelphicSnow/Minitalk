/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:35:00 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/29 18:00:10 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (c == 0)
		return (ptr + ft_strlen(s));
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
