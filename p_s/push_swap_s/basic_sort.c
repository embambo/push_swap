/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:09:57 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 12:04:43 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max_num(int *stack, int size)
{
	int	i;
	int	max;
	int	match;

	if(size == 0)
		return (-1);
	i = 0;
	max = 0;
	match = 0;
	max = stack[i];
	while(i < size)
	{
		if(max < stack[i])
		{
			max = stack[i];
			match = i;
		}
		i++;
	}
	return (match);
}

int	find_min_num(int *stack, int size)
{
	int	i;
	int	min;
	int	match;

	if(size == 0)
		return (-1);
	i = 0;
	match = 0;
	min = stack[i];
	while(i < size)
	{
		if(min > stack[i])
		{
			min = stack[i];
			match = i;
		}
		i++;
	}
	return (match);
}

void	first_min(t_stacks *stacks)
{
	int	min;

	min = find_min_num(stacks->a_stack, stacks->a_size);
	if(min <= stacks->a_size / 2)
		while(min--)
			ra(stacks);
	else
		while((stacks->a_size - min++) > 0)
			rra(stacks);
}
