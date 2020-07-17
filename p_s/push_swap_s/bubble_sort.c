/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:07:55 by embambo           #+#    #+#             */
/*   Updated: 2020/07/17 14:13:42 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void		swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void		bubble_sort(int *a, int len)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < len)
	{
		while (j < len + 1)
		{
			if (a[j] > a[i])
			{
				swap(&a[j], &a[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

static void		ft_reset(_Bool *wrd_first, int *cntr)
{
	*wrd_first = 0;
	*cntr = 0;
}

char			*ft_nxt_num_adrs(char *s, _Bool reset)
{
	static int		cntr;
	static _Bool	wrd_first;
	char			*num;

	num = NULL;
	if (reset)
	{
		ft_reset(&wrd_first, &cntr);
		return (num);
	}
	if ((*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')) && !wrd_first)
	{
		while (((s[cntr] >= '0' && s[cntr] <= '9') || s[cntr] == '+' ||
				s[cntr] == '-') && s[cntr])
			++cntr;
		wrd_first = 1;
		return (s);
	}
	while (((s[cntr] >= 9 && s[cntr] <= 13) || s[cntr] == 32) && s[cntr])
		++cntr;
	num = s + cntr;
	while (((s[cntr] >= '0' && s[cntr] <= '9') || s[cntr] == '+' ||
			s[cntr] == '-') && s[cntr])
		++cntr;
	return (num);
}
