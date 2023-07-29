/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:16:46 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/29 16:39:14 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	minus_sign;
	int	result;

	result = 0;
	minus_sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr ++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus_sign *= -1;
		nptr ++;
	}
	while (*nptr != '\0' && *nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - 48);
		nptr ++;
	}
	return (result * minus_sign);
}
