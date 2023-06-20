/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:45:15 by ykhourba          #+#    #+#             */
/*   Updated: 2022/10/26 13:37:58 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*item;

	if (!(lst) || !del)
		return ;
	while ((*lst) != NULL)
	{
		item = (*lst);
		*lst = (*lst)->next;
		ft_lstdelone(item, del);
	}
	*lst = NULL;
}
