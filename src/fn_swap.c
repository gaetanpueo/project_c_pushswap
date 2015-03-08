/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:01:12 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/08 15:01:15 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_tab		*fn_swap(t_tab *tab)
{
	int		tmp;

	tab = tab->deb;
	if (!tab->next)
		return (tab);
	tmp = tab->x;
	tab->x = tab->next->x;
	tab->next->x = tmp;
	return (tab);
}

t_tab		*fn_send(t_tab **l_a, t_tab *l_b)
{
	t_tab	*tab;

	*l_a = first_rot(*l_a);
	if ((*l_a)->next)
	{
		tab = (*l_a)->prev;
		(*l_a)->prev = (*l_a)->prev->prev;
		(*l_a)->prev->next = tab->next;
		tab->next = tab->prev = NULL;
	}
	else
	{
		tab = (*l_a);
		*l_a = NULL;
	}
	if (!l_b)
	{
		l_b = tab;
		l_b->next = NULL;
		l_b->prev = NULL;
		l_b->deb = l_b;
	}
	else
		l_b = fn_send_b(tab, l_b);
	return (l_b);
}

t_tab		*first_rot(t_tab *tab)
{
	t_tab	*tmp;
	int		x;

	tab = tab->deb;
	if (!tab->next)
		return (tab);
	x = tab->x;
	tmp = tab->next;
	tab->deb = tmp;
	tab = tab->next;
	while (tab->x != x)
	{
		tab->deb = tmp;
		tab = tab->next;
	}
	return (tmp);
}

t_tab		*last_rot(t_tab *tab)
{
	t_tab	*tmp;
	int		x;

	tab = tab->deb;
	if (!tab->next)
		return (tab);
	x = tab->x;
	tmp = tab->prev;
	tab->deb = tmp;
	tab = tab->prev;
	while (tab->x != x)
	{
		tab->deb = tmp;
		tab = tab->prev;
	}
	return (tmp);
}

t_tab	*fn_send_b(t_tab *tab, t_tab *l_b)
{
	l_b = l_b->deb;
	if (!l_b->prev)
		tab->prev = l_b;
	else
		tab->prev = l_b->prev;
	l_b->prev = tab;
	tab->next = l_b;
	tab->prev->next = tab;
	l_b = last_rot(l_b);
	return(l_b);
}
