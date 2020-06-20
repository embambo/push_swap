/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/20 10:07:52 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/checker.h"

static int		ft_check(int ac, char **av)
{
	int			ret;
	char		*str;

	if (ac == 2 && ft_strcmp(av[1], "-v") == 0)
		return (-1);
	if (ac == 2 && (ret = ft_check_arg(av[1])) < 3)
		if (ret == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
	if (ac > 2 && (str = ft_join_args(av)) &&
		(ret = ft_check_arg(str)) < 3)
	{
		if (ret == -1)
		{
			ft_putstr_fd("Error\n", 2);
			ft_memdel((void **)(&str));
			return (-1);
		}
		ft_memdel((void **)(&str));
	}
	return (0);
}

static void		ft_free_stacks(t_stacks *stacks)
{
	ft_memdel((void **)(&stacks->stk_a));
	ft_memdel((void **)(&stacks->stk_b));
	ft_memdel((void **)(&stacks));
}

int				main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 2)
		return (0);
	if (ft_check(ac, av) == -1)
		return (-1);
	stacks = ft_build_stacks(ac, av);
	if (ft_do_ops(av, stacks) == -1)
	{
		ft_free_stacks(stacks);
		return (-1);
	}
	ft_validate_stack(stacks);
	ft_free_stacks(stacks);
//	sleep(60);
	return (0);
}
