/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concater.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:23:48 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/22 19:23:49 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCATER_H
# define CONCATER_H

# include "minishell.h"

t_cmdlst	*ft_concater(t_cmdlst *head);
void		ft_free_garbage(t_lsttoken *item, char *str1, char *str2);
int			ft_link_nodes(t_lsttoken *item);
void		concate_cmd(t_lsttoken **head);
void		ft_concate_redir(t_lsttoken **head);

#endif
