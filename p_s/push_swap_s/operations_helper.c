/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:59:14 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 14:03:47 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		process_moves(t_moves *moves, t_stacks *stacks)
{
	while(moves->a_moves)
	{
		if(ft_strequ(moves->a_rot, "ra"))
			ra(stacks);
		else
			rra(stacks);
		moves->a_moves--;
	}
	while(moves->b_moves)
	{
		if(ft_strequ(moves->b_rot, "rb"))
			rb(stacks);
		else
			rrb(stacks);
		moves->b_moves--;
	}
}

static	void		push_all_leftovers(t_stacks *stacks)
{
	int	i;

	i = 0;
	while(stacks->a_size > 2)
	{
		i = find_min_num(stacks->a_stack, stacks->a_size);
		if(i == 0)
			pb(stacks);
		else if(i <= stacks->a_size / 2)
			ra(stacks);
		else if(i > stacks->a_size / 2)
			rra(stacks);
	}
}


int			find_a_place(int *stack, int size, int elem, char **rot_type)
{
	int	i;
	int	place;

	i = 0;
	place = 0;
	if (size == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (size == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max_num(stack, size)] ||
			elem < stack[find_min_num(stack, size)])
		place = find_min_num(stack, size);
	else
		while (i < size)
		{
			if (elem > stack[i] && ((i + 1 < size && elem < stack[i + 1]) ||
						(i + 1 == size && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_a_rot(size, place, rot_type));
}


static	void		push_back(t_stacks *stacks)
{
	int	rot;
	char	*rot_type;

	rot = 0;
	rot_type = ft_strnew(3);
	while(stacks->b_size)
	{
		rot = find_a_place(stacks->a_stack, stacks->a_size,
				stacks->b_stack[0], &rot_type);
		while(rot > 0)
		{
			if(ft_strequ(rot_type, "ra"))
				ra(stacks);
			else
				rra(stacks);
			rot--;
		}
		pa(stacks);
	}
	first_min(stacks);
	free(rot_type);
}

void			sort_large(t_stacks *stacks)
{
	t_moves		*top_moves;
	int		optimiser;
	optimiser = (stacks->a_size > 200) ? 50 : 2;
	while(stacks->b_size != 2)
		pb(stacks);
	while(stacks->a_size > optimiser)
	{
		top_moves = least_moves_betweenA_B(stacks);
		while(top_moves->c_moves)
		{
			if(ft_strequ(top_moves->c_rot, "rr"))
				rr(stacks);
			else
				rrr(stacks);
			top_moves->c_moves--;
		}
		process_moves(top_moves, stacks);
		pb(stacks);
		delete_moves(&top_moves);
	}
	push_all_leftovers(stacks);
	push_back(stacks);
}
