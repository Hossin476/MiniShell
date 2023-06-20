/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:28:10 by ykhourba          #+#    #+#             */
/*   Updated: 2022/10/17 18:16:48 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	while (len > 0 && haystack[i] && i < len)
	{
		j = 0;
		while ((j + i < len) && (needle[j] == haystack[i + j]))
		{
			j++;
			if (j == n_len)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
