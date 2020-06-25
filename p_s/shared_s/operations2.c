/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:20:28 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 13:45:17 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_s/push_swap.h"

void	rra(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->a_size < 2)
		return ;
	i = stacks->a_size - 1;
	tmp = stacks->a_stack[i];
	while (i > 0)
	{
		stacks->a_stack[i] = stacks->a_stack[i - 1];
		i--;
	}
	stacks->a_stack[0] = tmp;
	ft_putstr("rra\n");
}

void	rrb(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->b_size < 2)
		return ;
	i = stacks->b_size - 1;
	tmp = stacks->b_stack[i];
	while (i > 0)
	{
		stacks->b_stack[i] = stacks->b_stack[i - 1];
		i--;
	}
	stacks->b_stack[0] = tmp;
	ft_putstr("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->a_size > 1)
	{
		i = stacks->a_size - 1;
		tmp = stacks->a_stack[i];
		while (i-- > 0)
		{
			stacks->a_stack[i + 1] = stacks->a_stack[i];
		}
		stacks->a_stack[0] = tmp;
	}
	if (stacks->b_size > 1)
	{
		i = stacks->b_size - 1;
		tmp = stacks->b_stack[i];
		while (i > 0)
		{
			stacks->b_stack[i] = stacks->b_stack[i - 1];
			i--;
		}
		stacks->b_stack[0] = tmp;
	}
	ft_putstr("rrr\n");
}
