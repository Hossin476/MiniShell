/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:24:32 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/25 12:23:56 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*trimed;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL)
	{
		if (i == len)
			break ;
		i++;
	}
	if (i == len)
		return (ft_strdup("\0"));
	while (len > 0 && ft_strchr(set, s1[len]) != NULL)
		len--;
	trimed = ft_substr(s1, i, (len + 1) - i);
	return (trimed);
}
