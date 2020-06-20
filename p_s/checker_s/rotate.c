/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/20 09:25:55 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/checker.h"

void				ft_r_rotate(t_stacks *stacks, int mode)
{
	int		tmp;
	int		cntr;

	if (mode == 0 && (stacks->stk_size - 1) - stacks->stk_a_t >= 1)
	{
		tmp = (stacks->stk_a)[stacks->stk_size - 1];
		cntr = stacks->stk_size;
		while (--cntr - 1 >= stacks->stk_a_t)
			(stacks->stk_a)[cntr] = (stacks->stk_a)[cntr - 1];
		(stacks->stk_a)[stacks->stk_a_t] = tmp;
	}
	if (mode == 1 && (stacks->stk_size - 1) - stacks->stk_b_t >= 1)
	{
		tmp = (stacks->stk_b)[stacks->stk_size - 1];
		cntr = stacks->stk_size;
		while (--cntr - 1 >= stacks->stk_b_t)
			(stacks->stk_b)[cntr] = (stacks->stk_b)[cntr - 1];
		(stacks->stk_b)[stacks->stk_b_t] = tmp;
	}
	if (mode == 2)
		ft_r_rotate(stacks, 0);
	if (mode == 2)
		ft_r_rotate(stacks, 1);
}
