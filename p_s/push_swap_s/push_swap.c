/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:34:22 by embambo           #+#    #+#             */
/*   Updated: 2020/06/25 11:49:53 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc,char **argv)
{
	t_stacks	*stacks;

	if(argc > 1)
	{
		stacks = (t_stacks*)malloc(sizeof(t_stacks));
		check_argv(stacks, argv, argc);
		sort(stacks);
		delete_stacks(&stacks);
	}
	//sleep(60);
	return (0);
}
