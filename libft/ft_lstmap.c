/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:11:44 by ykhourba          #+#    #+#             */
/*   Updated: 2022/10/26 11:27:30 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*ptr;
	t_list	*item;

	if (!f || !del)
		return (NULL);
	newlist = NULL;
	ptr = lst;
	while (ptr != NULL)
	{
		item = ft_lstnew(f(ptr->content));
		if (!item)
		{
			ft_lstclear(&newlist, del);
			return (newlist);
		}
		ft_lstadd_back(&newlist, item);
		ptr = ptr->next;
	}
	return (newlist);
}
