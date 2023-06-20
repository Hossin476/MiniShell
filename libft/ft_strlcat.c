/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:45:31 by ykhourba          #+#    #+#             */
/*   Updated: 2022/10/19 14:14:46 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;

	i = 0;
	if (dst == NULL)
		lendst = 0;
	else
		lendst = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= lendst)
		return (ft_strlen((char *)src) + dstsize);
	while (src[i] != '\0' && (i < (dstsize - lendst - 1)))
	{
		dst[lendst + i] = (char)src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (ft_strlen((char *)src) + lendst);
}
