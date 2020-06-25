/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <embambo@student.wethinkcode.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:11:39 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 15:05:10 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atol(const char *str)
{
	long	ans;
	long	sign;
	size_t	num_cnt;

	ans = 0;
	sign = 1;
	num_cnt = 0;
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str == '0')
		++str;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		ans = (ans * 10) + (*str++ - 48);
		if (num_cnt > 18)
			return (sign == -1 ? 0 : -1);
		++num_cnt;
	}
	return (ans * sign);
}
