/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/20 09:42:23 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct	s_stacks
{
	int			*stk_a;
	int			stk_a_t;
	int			*stk_b;
	int			stk_b_t;
	int			stk_size;
}				t_stacks;

void			ft_swap(t_stacks *stacks, int mode);
void			ft_push(t_stacks *stacks, int mode);
void			ft_rotate(t_stacks *stacks, int mode);
void			ft_r_rotate(t_stacks *stacks, int mode);
void			ft_print_stacks(t_stacks *stacks);
void			ft_validate_stack(t_stacks *stacks);

int				ft_check_arg(const char *str);
int				ft_check_min_max(const char *num_adrs);
int				ft_count_nums(const char *str);
int				ft_do_ops(char **av, t_stacks *stacks);
int				ft_check_spaces(const char *str);

long			ft_atol(const char *str);

char			*ft_nxt_num_adrs(char *s, _Bool reset);
char			*ft_join_args(char **av);

t_stacks		*ft_build_stacks(int ac, char **av);

#endif
