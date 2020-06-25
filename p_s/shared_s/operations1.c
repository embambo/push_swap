/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:55:06 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 13:44:35 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_s/push_swap.h"

void	ra(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->a_size < 2)
		return ;
	i = 1;
	tmp = stacks->a_stack[0];
	while (i < stacks->a_size)
	{
		stacks->a_stack[i - 1] = stacks->a_stack[i];
		i++;
	}
	stacks->a_stack[i - 1] = tmp;
	ft_putstr("ra\n");
}

void	rb(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->b_size < 2)
		return ;
	i = 1;
	tmp = stacks->b_stack[0];
	while (i < stacks->b_size)
	{
		stacks->b_stack[i - 1] = stacks->b_stack[i];
		i++;
	}
	stacks->b_stack[i - 1] = tmp;
	ft_putstr("rb\n");
}

void	rr(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->a_size > 1)
	{
		i = 1;
		tmp = stacks->a_stack[0];
		while (i++ < stacks->a_size)
		{
			stacks->a_stack[i - 2] = stacks->a_stack[i - 1];
		}
		stacks->a_stack[i - 2] = tmp;
	}
	if (stacks->b_size > 1)
	{
		i = 1;
		tmp = stacks->b_stack[0];
		while (i < stacks->b_size)
		{
			stacks->b_stack[i - 1] = stacks->b_stack[i];
			i++;
		}
		stacks->b_stack[i - 1] = tmp;
	}
	ft_putstr("rr\n");
}
