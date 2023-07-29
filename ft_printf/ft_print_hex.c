/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:02:45 by tkajanek          #+#    #+#             */
/*   Updated: 2023/02/09 15:30:12 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_x(unsigned int p, char a)
{
	char	b;

	if (p >= 16)
	{
		ft_put_x(p / 16, a);
		ft_put_x(p % 16, a);
	}
	else
	{
		if (p <= 9)
		{
			b = p + '0';
			write(1, &b, 1);
		}
		else if (a == 'x')
		{
			b = p - 10 + 'a';
			write(1, &b, 1);
		}
		else
		{
			b = p - 10 + 'A';
			write(1, &b, 1);
		}
	}
}

int	ft_print_hex(va_list args, char a)
{
	unsigned int	p;
	int				i;

	p = va_arg(args, unsigned int);
	i = 0;
	if (p == 0)
		i += write(1, "0", 1);
	else
	{
		ft_put_x(p, a);
		i += ft_ptr_len (p);
	}
	return (i);
}
