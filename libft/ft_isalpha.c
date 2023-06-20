/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:58:53 by ykhourba          #+#    #+#             */
/*   Updated: 2022/10/17 16:56:53 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int argument)
{
	if ((argument >= 'A' && argument <= 'Z')
		|| (argument >= 'a' && argument <= 'z'))
		return (1);
	return (0);
}
