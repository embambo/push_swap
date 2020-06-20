/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/20 09:24:52 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/checker.h"

void				ft_print_stacks(t_stacks *stacks)
{
	int		cntr;

	ft_putstr("\n\t\tSTACK A:\n");
	cntr = stacks->stk_a_t;
	while (stacks->stk_a_t < stacks->stk_size && cntr < stacks->stk_size)
	{
		ft_putstr("\t\t");
		ft_putnbr((stacks->stk_a)[cntr]);
		ft_putchar('\n');
		++cntr;
	}
	ft_putstr("\n\t\tSTACK B:\n");
	cntr = stacks->stk_b_t;
	while (stacks->stk_b_t < stacks->stk_size && cntr < stacks->stk_size)
	{
		ft_putstr("\t\t");
		ft_putnbr((stacks->stk_b)[cntr]);
		ft_putchar('\n');
		++cntr;
	}
	ft_putchar('\n');
}
