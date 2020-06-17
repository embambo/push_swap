/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/16 15:00:23 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void		ft_use_commands(int n, t_stack *stks)
{
	void		(*oper[11])(t_stack*);

	oper[1] = &ft_sa;
	oper[2] = &ft_sb;
	oper[3] = &ft_ss;
	oper[4] = &ft_pa;
	oper[5] = &ft_pb;
	oper[6] = &ft_ra;
	oper[7] = &ft_rb;
	oper[8] = &ft_rr;
	oper[9] = &ft_rra;
	oper[0] = &ft_rrb;
	oper[10] = &ft_rrr;
	oper[n](stks);
}

void				printing_stack2(int a, int size)
{
	int i;

	i = 0;
	if (a < 0)
		exit(1);
	while (i <= size - 1)
	{
		ft_putnbr(a);
		ft_putstr(",");
		ft_putnbr(size);
	}
	write(1, "\n", 1);
	return ;
}

int				ft_game_act(char *argument, t_stack *stks)
{
	int			oper;

	oper = 0;
	free(argument);
	if (oper >= 0 && oper < 11)
		ft_use_commands(oper, stks);
	else if (oper == 11)
		return (-1);
	else if (oper == 12)
		return (0);
	else if (oper == 13)
	{
		if (stks->elems_a < stks->size)
		{
			printing_stack2(stks->elems_a, stks->size);
			ft_putendl("\n");
		}
		if (ft_is_stack_in_order(stks) == 1)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	else if (oper == 14)
		ft_print_stacks(stks);
	else
		return (0);
	return (0);
}
