/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:47:49 by tkajanek          #+#    #+#             */
/*   Updated: 2023/02/09 15:30:15 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_u_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_u_itoa(unsigned int n)
{
	int		len;
	char	*str;

	len = num_u_len(n);
	str = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	len--;
	while (n != 0)
	{
		str[len] = (n % 10) + '0';
		len --;
		n /= 10;
	}
	return (str);
}

int	ft_print_unsigned(va_list args)
{
	int				i;
	unsigned int	num;
	char			*arr;

	num = va_arg(args, unsigned int);
	arr = ft_u_itoa(num);
	i = write(1, arr, ft_strlen (arr));
	free (arr);
	return (i);
}
