/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:28:17 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/15 18:13:44 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*pbig;

	pbig = (char *)big;
	i = 0;
	j = 0;
	if (little[0] == '\0')
		return (pbig);
	while (pbig[i] != '\0' && i < len)
	{
		while (pbig[i + j] == little[j] && pbig[i + j] != '\0' && (i + j < len))
		{
			j++;
			if (little[j] == '\0')
				return (&pbig[i]);
		}
		i++;
		j = 0;
	}	
	return (NULL);
}
