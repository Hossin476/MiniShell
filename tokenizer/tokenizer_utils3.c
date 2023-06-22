/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:17:11 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:17:12 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_lsttoken	*ft_lst_new(void)
{
	t_lsttoken	*item;

	item = malloc(sizeof(t_lsttoken));
	if (!item)
		return (NULL);
	item->next = NULL;
	return (item);
}

void	ft_lstaddback(t_lsttoken **lst, t_lsttoken *new)
{
	t_lsttoken	*ptr;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}
