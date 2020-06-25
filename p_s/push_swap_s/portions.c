/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:37:54 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 12:06:40 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	find_b_place(int *stacks, int size, int elem, char **rot)
{
	int	i;
	int	place;

	i = 0;
	place = 0;
	if(size == 2 && elem > stacks[0] && elem < stacks[size - 1])
		place = 0;
	else if(size == 2 && elem < stacks[0] && elem > stacks[size - 1])
		place = 1;
	else if(elem > stacks[find_max_num(stacks, size)] || 
			elem < stacks[find_min_num(stacks, size)])
		place = find_max_num(stacks, size);
	else
		while (i < size)
		{
			if(elem < stacks[i] && ((i + 1 < size && elem > stacks[i + 1]) ||
						(i + 1 == size && elem > stacks[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_b_rot(size, place , rot));
}

static	int	find_common_moves(t_moves *moves)
{
	int	common;

	common = 0;
	if ((ft_strequ(moves->a_rot, "rra") && (ft_strequ(moves->b_rot, "rrb"))) ||
			(ft_strequ(moves->a_rot , "ra") && (ft_strequ(moves->b_rot, "rb"))))
	{
		common = (moves->a_moves > moves->b_moves ? moves->b_moves : moves->a_moves);
		if(common)
		{
			moves->c_rot = ft_strcpy(moves->c_rot, moves->a_rot);
			moves->c_rot[ft_strlen(moves->c_rot) - 1] = 'r';
			moves->b_moves -= common;
			moves->a_moves -= common;
		}
	}
	return (common);
}



static t_moves	*calculated_moves_a_to_b(t_stacks *stacks, int position)
{
	t_moves	*moves;

	moves = (t_moves*)malloc(sizeof(t_moves));
	moves->a_rot = ft_strnew(3);
	moves->b_rot = ft_strnew(3);
	moves->c_rot = ft_strnew(3);
	moves->elem = stacks->a_stack[position];
	moves->a_moves = find_a_rot(stacks->a_size, position, &(moves->a_rot));
	moves->b_moves = find_b_place(stacks->b_stack, stacks->b_size,stacks->a_stack[position], &(moves->b_rot));
	moves->c_moves = find_common_moves(moves);
	moves->tot = moves->a_moves + moves->b_moves + moves->c_moves + 1;
       return (moves);	

}

t_moves		*least_moves_betweenA_B(t_stacks *stacks)
{
	int		i;
	t_moves		*top_moves;
	t_moves		*moves;

	i = 0;
	while(i < stacks->a_size)
	{
		moves = calculated_moves_a_to_b(stacks, i);
		if (i == 0)
			top_moves = moves;
		else if(top_moves->tot > moves->tot)
		{
			delete_moves(&top_moves);
			top_moves = moves;
		}
		else
			delete_moves(&moves);
		i++;
	}
	return (top_moves);
}
