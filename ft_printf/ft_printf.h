/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:15:21 by tkajanek          #+#    #+#             */
/*   Updated: 2023/02/09 15:30:42 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_char(va_list args);
int		ft_print_str(va_list args);
int		ft_print_pointer(va_list args);
int		ft_ptr_len(uintptr_t p);
int		ft_print_integer(va_list args);
int		ft_print_unsigned(va_list args);
int		ft_print_hex(va_list args, char a);

#endif
