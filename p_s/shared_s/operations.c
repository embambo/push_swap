/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 09:38:11 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 13:53:20 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_s/push_swap.h"

void		sa(t_stacks *stacks)
{
	int	tmp;

	if(stacks ->a_size < 2)
		return ;
	tmp = stacks->a_stack[0];
	stacks->a_stack[0] = stacks->a_stack[1];
	stacks->a_stack[1] = tmp ;
	ft_putstr("sa\n");
}

void		sb(t_stacks *stacks)
{
	int	tmp;

	if(stacks->b_size < 2)
		return ;
	tmp = stacks->b_stack[0];
	stacks->b_stack[0] = stacks->b_stack[1];
	stacks->b_stack[1] = tmp;
	ft_putstr("sb\n");
}

void		ss(t_stacks *stacks)
{
	int	tmp;

	if(stacks->a_size > 1)
	{
		tmp = stacks->a_stack[0];
		stacks->a_stack[0] = stacks->a_stack[1];
		stacks->a_stack[1] = tmp;
	}
	if(stacks->b_size > 1)
	{
		tmp = stacks->b_stack[0];
		stacks->b_stack[0] = stacks->b_stack[1];
		stacks->b_stack[1] = tmp;
	}
	ft_putstr("ss\n");
}

void		pa(t_stacks *stacks)
{
	int	i;

	if(stacks->b_size == 0)
		return ;
	i = stacks->a_size;
	while(i--)
		stacks->a_stack[i + 1] = stacks->a_stack[i];
	stacks->a_stack[0] = stacks->b_stack[0];
	i = 0;
	while(i++ <= stacks->b_size - 1)
		stacks->b_stack[i - 1] = stacks->b_stack[i];
	stacks->a_size++;
	stacks->b_size--;
	ft_putstr("pa\n");
}

void		pb(t_stacks *stacks)
{
	int	i;

	if(stacks->a_size == 0)
		return ;
	i = stacks->b_size;
	while (i--)
		stacks->b_stack[i + 1] = stacks->b_stack[i];
	stacks->b_stack[0] = stacks->a_stack[0];
	i = 0;
	while(i++ <= stacks->a_size - 1)
		stacks->a_stack[i - 1] = stacks->a_stack[i];
	stacks->b_size++;
	stacks->a_size--;
	ft_putstr("pb\n");
}
