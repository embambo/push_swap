/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:25:57 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 13:54:35 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# define max_int 2147483647
#define min_int -2147483647

typedef struct	s_stacks
{
	int		*a_stack;
	int		*b_stack;
	int		a_size;
	int		b_size;
}			t_stacks;

typedef struct	s_moves
{
	int	a_moves;
	int	b_moves;
	int	c_moves;
	int	tot;
	int	elem;
	char	*a_rot;
	char	*b_rot;
	char	*c_rot;
}			t_moves;

/* exc_instruction_ch.c*/
void	exc_sa_ch(t_stacks *stacks);
void	exc_sb_ch(t_stacks *stacks);
void	exc_ss_ch(t_stacks *stacks);
void	exc_pa_ch(t_stacks *stacks);
void	exc_pb_ch(t_stacks *stacks);
/* exc_ra_ch*/
void	exc_ra_ch(t_stacks *stacks);
void	exc_rb_ch(t_stacks *stacks);
void	exc_rr_ch(t_stacks *stacks);
/*exc_rrr_ch */
void		exc_rra_ch(t_stacks *stacks);
void		exc_rrb_ch(t_stacks *stacks);
void		exc_rrr_ch(t_stacks *stacks);
/* gnl */

/* help sort */
int		find_max_num(int *stack, int size);
int		find_min_num(int *stack, int size);
void		first_min(t_stacks *stacks);
/* insttructions.c */
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stack);
void		pb(t_stacks *stacks);
/* is_sort.c */
int	is_it_sorted(int *stacks, int size);
void	delete_stacks(t_stacks **stacks);
void	delete_moves(t_moves **moves);
/* least5_moves_betweenA_B.c */
t_moves		*least_moves_betweenA_B(t_stacks *stacks);
/* more_instructions.c */
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
/* more_instructions_more.c */
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
/*find_rot */
int		find_a_rot(int len, int position, char **rot);
int		find_b_rot(int len, int position, char **rot);
/* sort.c */
void		sort(t_stacks *stacks);
/* sort_large.c */
void		sort_large(t_stacks *stack);
/* stacks.c */
void		check_argv(t_stacks *stacks, char **argv, int argc);
/*check if dup */
int		check_if_dup(int argc, char **argv);

#endif
