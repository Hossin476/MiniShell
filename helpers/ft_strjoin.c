/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:49:58 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/23 18:55:03 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*full_str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	full_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 +1));
	if (!full_str)
		return (NULL);
	while (*s1)
		full_str[i++] = *s1++;
	while (*s2)
		full_str[i++] = *s2++;
	full_str[i] = '\0';
	return (full_str);
}
