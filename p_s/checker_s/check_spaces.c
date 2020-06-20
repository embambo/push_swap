/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/20 09:22:44 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/checker.h"

int				ft_check_spaces(const char *str)
{
	int		cntr;

	cntr = 0;
	while (str[cntr])
	{
		if (cntr == 0 && (str[cntr] == '+' || str[cntr] == '-'))
			++cntr;
		if (str[cntr] == '+' || str[cntr] == '-')
			if (!(str[cntr - 1] >= 9 && str[cntr - 1] <= 13) &&
				!(str[cntr - 1] == 32))
				return (-1);
		++cntr;
	}
	return (0);
}
