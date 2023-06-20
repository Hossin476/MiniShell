/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:13:08 by ykhourba          #+#    #+#             */
/*   Updated: 2022/10/17 18:09:50 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>
char	*ft_strdup(const char *s1)
{
	int		len;
	char	*d1;

	if(!s1)
		return(NULL);
	len = ft_strlen(s1);
	d1 = (char *)malloc(len + 1);
	if (!d1)
		return (NULL);
	while (*s1)
	{
		*d1 = *s1;
		d1++;
		s1++;
	}
	*d1 = '\0';
	return (d1 - len);
}
