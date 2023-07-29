/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:53:50 by tkajanek          #+#    #+#             */
/*   Updated: 2023/02/09 15:30:18 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list args, const char *format, int i)
{
	int	read;

	if (format[i] == 'c')
		read = ft_print_char(args);
	if (format[i] == 's')
		read = ft_print_str(args);
	if (format[i] == 'p')
		read = ft_print_pointer(args);
	if (format[i] == 'd' || format[i] == 'i')
		read = ft_print_integer(args);
	if (format[i] == 'u')
		read = ft_print_unsigned(args);
	if (format[i] == '%')
		read = write(1, "%", 1);
	if (format[i] == 'x' || format[i] == 'X')
		read = ft_print_hex(args, format[i]);
	return (read);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		read;
	va_list	args;
	char	a;

	va_start (args, format);
	read = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			read += ft_check_format(args, format, i + 1);
			i++;
		}
		else
		{
			a = format[i];
			read += write (1, &a, 1);
		}
		i++;
	}
	va_end(args);
	return (read);
}
