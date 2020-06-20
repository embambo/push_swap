/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                          	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/20 09:25:18 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/checker.h"

void				ft_push(t_stacks *stacks, int mode)
{
	if (mode == 0 && (stacks->stk_size - 1) - stacks->stk_b_t >= 0)
	{
		--stacks->stk_a_t;
		(stacks->stk_a)[stacks->stk_a_t] = (stacks->stk_b)[stacks->stk_b_t];
		++stacks->stk_b_t;
	}
	if (mode == 1 && (stacks->stk_size - 1) - stacks->stk_a_t >= 0)
	{
		--stacks->stk_b_t;
		(stacks->stk_b)[stacks->stk_b_t] = (stacks->stk_a)[stacks->stk_a_t];
		++stacks->stk_a_t;
	}
}
