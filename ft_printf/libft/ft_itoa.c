/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:42:16 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/29 17:31:32 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (0);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	len --;
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = num_len(n);
	str = (char *)ft_calloc(sizeof(char), (len + 2));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
	{
		str[len--] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
