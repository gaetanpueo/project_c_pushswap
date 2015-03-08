/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:01:12 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/08 15:01:15 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	verif_num(char **av)
{
	int		i;
	long	num;

	i = 1;
	num = 0;
	while (av[i])
	{
		num = ft_atoli(av[i]);
		if (num >= 2147483647 || num <= -2147483647)
		{
			ft_putendl(C_RED"Error");
			exit (0);
		}
		i++;
	}
}

int		check_sort(t_tab *tab)
{
	int		x;

	tab = tab->deb;
	x = tab->x;
	tab = tab->next;
	while (tab != tab->deb)
	{
		if (tab->x < x)
			return (0);
		x = tab->x;
		tab = tab->next;
	}
	return (1);
}

int		ft_max(t_tab *tab)
{
	int		max;

	tab = tab->deb;
	max = tab->x;
	tab = tab->next;
	while (tab != tab->deb)
	{
		if (tab->x > max)
			max = tab->x;
		tab = tab->next;
	}
	return (max);
}

int		ft_min(t_tab *tab)
{
	int		min;

	tab = tab->deb;
	min = tab->x;
	tab = tab->next;
	while (tab != tab->deb)
	{
		if (tab->x < min)
			min = tab->x;
		tab = tab->next;
	}
	return (min);
}

void	display_2(int flag, char *str)
{
	if (flag == 1 || !flag)
	{
		if (flag)
			str = ft_strcolor(str);
		ft_putendl(str);
	}
}
