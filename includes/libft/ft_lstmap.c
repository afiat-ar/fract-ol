/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:49:38 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/06/03 13:37:10 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*temp;

	if (lst)
	{
		temp = lst;
		new_lst = ft_lstnew(f(temp->content));
		if (!new_lst)
			return (NULL);
		temp = temp->next;
		while (temp)
		{
			new_elem = ft_lstnew(f(temp->content));
			if (!new_elem)
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			ft_lstadd_back(&new_lst, new_elem);
			temp = temp->next;
		}
		return (new_lst);
	}
	return (NULL);
}
