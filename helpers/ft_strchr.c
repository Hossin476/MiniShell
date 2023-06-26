/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:48:43 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/25 12:23:40 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str || c == '\0')
		return (NULL);
	while (*str != (char)c)
	{
		if (!*str)
			return (0);
		str++;
	}
	return ((char *)str);
}
