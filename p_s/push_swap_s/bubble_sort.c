/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:07:55 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 12:04:52 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exc_rra_ch(t_stacks *stacks)
{
	int	i;
	int	tmp;

	if(stacks->a_size < 2)
		return ;
	i = stacks->a_size - 1;
	tmp = stacks->a_stack[i];
	while(i > 0)
	{
		stacks->a_stack[i] = stacks->a_stack[i - 1];
		i--;
	}
	stacks->a_stack[0] = tmp;
}

void		exc_rrb_ch(t_stacks *stacks)
{
	int	i;
	int	tmp;

	if(stacks->b_size < 2)
		return ;
	i = stacks->b_size - 1;
	tmp = stacks->b_stack[i];
	while(i > 0)
	{
		stacks->b_stack[i] = stacks->b_stack[i - 1];
		i--;
	}
	stacks->b_stack[0] = tmp;
}

void		exc_rrr_ch(t_stacks *stacks)
{
	int	i;
	int	tmp;
	
	if(stacks->a_size > 1)
	{
		i = stacks->a_size - 1;
		tmp = stacks->a_stack[i];
		while (i-- > 0)
		{
			stacks->a_stack[i + 1] = stacks->a_stack[i];
		}
		stacks->a_stack[0] = tmp;
	}
	if(stacks->b_size > 1)
	{
		i = stacks->b_size - 1;
		tmp = stacks->b_stack[i];
		while(i > 0)
		{
			stacks->b_stack[i] = stacks->b_stack[i - 1];
			i--;
		}
		stacks->b_stack[0] = tmp;
	}
}
