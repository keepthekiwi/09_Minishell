/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:18:59 by nhaas             #+#    #+#             */
/*   Updated: 2021/07/12 11:58:19 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*new;

	new = 0;
	while (lst != NULL)
	{
		element = ft_lstnew(f(lst->content));
		if (element == NULL)
			ft_lstclear(&new, del);
		else
			ft_lstadd_back(&new, element);
		lst = lst->next;
	}
	return (new);
}
