/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:07:02 by embambo           #+#    #+#             */
/*   Updated: 2020/07/17 14:18:46 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int			is_sorted(int *array, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void		free_array(t_array *array)
{
	free(array->array_a);
	free(array->array_b);
	free(array->array_c);
	free(array);
	array = NULL;
}

void	delete_stacks(t_array **stacks)
{
	if(*stacks)
	{
		if((*stacks)->array_a)
			free((*stacks)->array_a);
		if((*stacks)->array_b)
			free((*stacks)->array_b);
		free(*stacks);
		*stacks = NULL;
	}
}

int				ft_count_numbs(const char *str)
{
	int		cntr;
	int		num_cnt;
	_Bool	swtch;

	cntr = 0;
	num_cnt = 0;
	swtch = 0;
	while (str[cntr])
	{
		if ((str[cntr] == '+' || str[cntr] == '-' || (str[cntr] >= '0' &&
			str[cntr] <= '9')) && !swtch)
		{
			++num_cnt;
			swtch = 1;
		}
		if ((str[cntr] >= 9 && str[cntr] <= 13) || str[cntr] == 32)
			swtch = 0;
		++cntr;
	}
	return (num_cnt);
}

