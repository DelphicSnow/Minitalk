/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:29:02 by tkajanek          #+#    #+#             */
/*   Updated: 2023/02/03 20:09:05 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	char	a;
	int		i;	

	a = va_arg(args, int);
	i = write(1, &a, 1);
	return (i);
}

int	ft_print_str(va_list args)
{
	int			i;
	const char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	i = write(1, str, ft_strlen(str));
	return (i);
}

int	ft_print_integer(va_list args)
{
	int		i;
	int		num;
	char	*arr;

	num = va_arg(args, int);
	arr = ft_itoa(num);
	i = write(1, arr, ft_strlen(arr));
	free (arr);
	return (i);
}
