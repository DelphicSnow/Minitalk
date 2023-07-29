/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:54:26 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/27 18:11:54 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;

	count = 0;
	current = lst;
	while (current != 0)
	{
		count ++;
		current = current->next;
	}
	return (count);
}
/*
int main() {
t_list  first;
t_list  second;
t_list  last;

first.next = &second;
second.next = &last;
last.next = 0;
ft_lstsize(&first);
  return (0);
}*/