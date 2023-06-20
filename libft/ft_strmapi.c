/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:22:53 by ykhourba          #+#    #+#             */
/*   Updated: 2022/11/09 21:00:27 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*str;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
			i++;
	}
	str[i] = '\0';
	return (str);
}

char to_upper(unsigned int i,char s)
{
	(void)i;
	if(s >='a' && s <='z')
		return s-=32;
	return s;
}
#include<stdio.h>
int main()
{
	printf("%s",ft_strmapi("aiwuhasdhaud",to_upper));
}
