/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:07:02 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 12:05:05 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_sorted(int *stacks, int size)
{
	int	i;
	if(size == 1)
		return(1);
	i = 0;
	while(i < size - 1)
	{
		if(stacks[i] > stacks[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	delete_stacks(t_stacks **stacks)
{
	if(*stacks)
	{
		if((*stacks)->a_stack)
			free((*stacks)->a_stack);
		if((*stacks)->b_stack)
			free((*stacks)->b_stack);
		free(*stacks);
		*stacks = NULL;
	}
}

void	delete_moves(t_moves **moves)
{
	free((*moves)->a_rot);
	free((*moves)->b_rot);
	free((*moves)->c_rot);
	free(*moves);
	*moves = NULL;
}
