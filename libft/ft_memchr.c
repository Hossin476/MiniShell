/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:20:35 by ykhourba          #+#    #+#             */
/*   Updated: 2022/11/17 20:18:56 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	ch;
	void			*ptr;

	ch = (unsigned char)c;
	src = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*src == ch)
		{
			ptr = src;
			return (ptr);
		}
		src++;
	}
	return (NULL);
}

