/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:38:58 by ykhourba          #+#    #+#             */
/*   Updated: 2022/11/09 20:56:33 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ds;
	char		*sr;
	size_t		i;

	ds = (char *)dst;
	sr = (char *)src;
	if (!ds && !sr)
		return (NULL);
	if (ds > sr)
	{
		i = 0;
		while (i++ < len)
		{
			ds[len - i] = sr[len - i];
		}
		return (dst);
	}
	i = -1;
	while (++i < len)
	{
		ds[i] = sr[i];
	}
	return (dst);
}
