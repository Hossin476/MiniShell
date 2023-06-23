/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:11:16 by ykhourba          #+#    #+#             */
/*   Updated: 2023/06/23 19:09:08 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"

static int	checkiflong(char *str)
{
	int	counter;

	counter = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str > '0' && *str <= '9')
	{
		str++;
		counter++;
	}
	if (counter > 18)
		return (1);
	return (0);
}

static int	check_return(char *str)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int	signe;
	int	res;
	    
	if(!str)
		return(0);
	if (checkiflong((char *)str) == 1)
		return (check_return((char *)str));
	signe = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	signe *= -1;
	if (*str == '-' || *str == '+')
	str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * signe);
}
