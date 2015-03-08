/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:01:12 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/08 15:01:15 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	*ft_strcolor(char *str)
{
	char	*ch;
	int		i;
	int		j;

	if (!ft_strrchr(str, ' '))
		ch = str;
	else
		ch = ft_strrchr(str, ' ') ;
	i = ch - str;
	ch = ft_strjoin(C_MAGENTA, ch);
	ch = ft_strjoin(ch, C_NONE);
	j = 0;
	while (ch[j])
	{
		str[i] = ch[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	affiche(t_tab *l_a, t_tab *l_b, char *str, int flag)
{
	char	*ch;

	if (flag == 3 && check_sort(l_a) && !l_b)
		ft_putstr(C_MAGENTA);
	ch = ft_strdup(str);
	ch = delete_spaces(ch);
	if (!ft_strrchr(ch, ' '))
		ft_putendl(ch);
	else
	{
		ch = ft_strrchr(ch, ' ') + 1;
		ft_putendl(ch);
	}
	ft_putstr(C_NONE);
	affiche_a(l_a);
	affiche_b(l_b);
	ft_putchar('\n');
}

void	gest_error(t_tab *tab)
{
	int		x;
	int		a;
	void	*test;

	tab = tab->deb;
	x = tab->x;
	test = tab;
	tab = tab->next;
	a = 0;
	while (test != tab->deb || !a)
	{
		while (test != tab && tab->x != x)
			tab = tab->next;
		if (x == tab->x && test != tab)
		{
			ft_putendl(C_RED"Error");
			exit(0);
		}
		tab = tab->next;
		x = tab->x;
		test = tab;
		tab = tab->next;
		a++;
	}
}
void	affiche_a(t_tab *l_a)
{
	ft_putstr("l_a : ");
	if (l_a)
	{
		l_a = l_a->deb;
		ft_putnbr(l_a->x);
		ft_putchar(' ');
		l_a = l_a->next;
		while (l_a && l_a->x != l_a->deb->x)
		{
			ft_putnbr(l_a->x);
			ft_putchar(' ');
			l_a = l_a->next;
		}
	}
}

void	affiche_b(t_tab *l_b)
{
	ft_putstr("\nl_b : ");
	if (l_b)
	{
		l_b = l_b->deb;
		ft_putnbr(l_b->x);
		ft_putchar(' ');
		l_b = l_b->next;
		while (l_b && l_b->x != l_b->deb->x)
		{
			ft_putnbr(l_b->x);
			ft_putchar(' ');
			l_b = l_b->next;
		}
	}
}
