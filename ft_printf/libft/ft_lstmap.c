/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:57:52 by tkajanek          #+#    #+#             */
/*   Updated: 2023/01/27 17:15:23 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew (f(lst->content));
	if (!new_list)
		return (NULL);
	temp = new_list;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = ft_lstnew(f(lst->content));
		if (!temp->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (new_list);
}
