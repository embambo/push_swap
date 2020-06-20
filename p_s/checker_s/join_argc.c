/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_argc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/20 09:45:12 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/checker.h"

char		*ft_join_args(char **av)
{
	int		cntr;
	char	*str;
	char	*tmp;

	cntr = 2;
	if (!av[1])
		return (NULL);
	if (ft_strcmp(av[1], "-v") == 0)
	{
		cntr = 3;
		str = ft_strdup(av[2]);
	}
	else
		str = ft_strdup(av[1]);
	while (av[cntr])
	{
		tmp = ft_strjoin(str, " ");
		ft_memdel((void **)(&str));
		str = ft_strjoin(tmp, av[cntr]);
		ft_memdel((void **)(&tmp));
		++cntr;
	}
	return (str);
}
