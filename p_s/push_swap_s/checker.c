/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 10:33:25 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	exc_rr(t_stacks *stacks, char *in)
{
	if(in[2] == '\0')
		exc_rr_ch(stacks);
	else if(in[2] == 'a' && in[3] == '\0')
		exc_rra_ch(stacks);
	else if(in[2] == 'b' && in[3] == '\0')
		exc_rrb_ch(stacks);
	else if(in[2] == 'r' && in[3] == '\0')
		exc_rrr_ch(stacks);
	else
		return(-1);
	return (0);
}

static int	exc_instructions(t_stacks *stacks,char *in)
{
	if(ft_strnequ(in, "rr", 2))
	{
		if(exc_rr(stacks, in))
			return (-1);	
	}
	else if(ft_strcmp(in , "sa") == 0)
		exc_sa_ch(stacks);
	else if(ft_strcmp(in, "sb") == 0)
		exc_sb_ch(stacks);
	else if(ft_strcmp(in , "ss") == 0)
		exc_ss_ch(stacks);
	else if(ft_strcmp(in, "pa") == 0)
		exc_pa_ch(stacks);
	else if (ft_strcmp(in, "pb") == 0)
		exc_pb_ch(stacks);
	else if (ft_strcmp(in, "ra") == 0)
		exc_ra_ch(stacks);
	else if (ft_strcmp(in, "rb") == 0)
		exc_rb_ch(stacks);
	else
		return (-1);
	return (0);
}

static int	get_instructions(t_stacks *stacks)
{
	char *in;
	int i;
	int	check = 0;

	i = 0;
	while(get_next_line(0, &in) == 1 && ++i)
	{
		check = exc_instructions(stacks, in);
		ft_strdel(&in);
		if (check == -1)
		{
			return (-1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			check_ins = 0;

	if(argc > 1)
	{
		if(check_if_dup(argc, argv))
		{
			ft_putendl("Error");
			exit(1);
		}
		else
		{
			stacks = (t_stacks*)malloc(sizeof(t_stacks));
			check_argv(stacks, argv, argc);
			check_ins = get_instructions(stacks);
			if (check_ins == -1)
			{
				ft_putendl("Error");
				return (0);
			}
			if(is_it_sorted(stacks->a_stack, stacks->a_size) && stacks->b_size == 0)
				ft_putstr("Ok\n");
			else
				ft_putstr("KO\n");
		}
		delete_stacks(&stacks);
	}
	return (0);
}
