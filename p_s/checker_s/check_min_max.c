/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/20 09:44:51 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/checker.h"

int				ft_check_min_max(const char *num_adrs)
{
	int		cntr;
	int		len;
	long	num;

	cntr = 0;
	if (num_adrs[cntr] == '+' || num_adrs[cntr] == '-')
		++cntr;
	len = 0;
	while (num_adrs[cntr] == '0')
		++cntr;
	while (num_adrs[cntr] && !((num_adrs[cntr] >= 9 && num_adrs[cntr] <= 13) ||
			(num_adrs[cntr] == 32)))
	{
		if (num_adrs[cntr] >= '0' && num_adrs[cntr] <= '9')
			++len;
		++cntr;
	}
	if (len > 10)
		return (-1);
	num = ft_atol(num_adrs);
	if (num > 2147483647 || num < -2147483648)
		return (-1);
	return (0);
}
