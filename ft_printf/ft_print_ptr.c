/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:07:12 by tkajanek          #+#    #+#             */
/*   Updated: 2023/02/14 14:53:27 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		p /= 16;
		len ++;
	}
	return (len);
}

static void	ft_put_ptr(uintptr_t p)
{
	char	a;

	if (p >= 16)
	{
		ft_put_ptr(p / 16);
		ft_put_ptr(p % 16);
	}
	else
	{
		if (p <= 9)
		{
			a = p + '0';
			write(1, &a, 1);
		}
		else
		{
			a = p - 10 + 'a';
			write(1, &a, 1);
		}
	}
}

int	ft_print_pointer(va_list args)
{
	uintptr_t	p;
	int			i;

	p = (uintptr_t)va_arg(args, void *);
	i = 0;
	if (p == 0)
		i += write(1, "(nil)", 5);
	else
	{	
		i += write(1, "0x", 2);
		ft_put_ptr (p);
		i += ft_ptr_len (p);
	}
	return (i);
}
