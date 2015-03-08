/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:01:12 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/08 15:01:15 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_tab	*creation(t_tab *tab, int ac, char **av)
{
	t_tab	*tmp;
	t_tab	*tmp2;
	int		i;

	i = 0;
	while (i < ac)
	{
		tmp = init_tmp(tmp, av, i);
		if (!tab)
		{
			tab = tmp;
			tmp2 = tab;
		}
		else
			tmp2 = creation_b(tmp2, tmp);
		tmp->deb = tab;
		i++;
		if (i < ac)
			tmp = tmp->next;
	}
	tab->prev = tmp;
	tmp->next = tab;
	return (tab);
}

t_tab	*creation_b(t_tab *tmp2, t_tab *tmp)
{
	tmp2->next = tmp;
	tmp2->next->prev = tmp2;
	tmp2 = tmp2->next;
	return (tmp2);
}

char	*raccourci(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 's' && str[i + 1] != 's' && str[i + 3] == 's' &&
			str[i + 4] != 's')
		{
			i++;
			str[i] = 's';
			str = fn_strchange(str, i, 3);
		}
		str = raccourci_b(str, &i);
		i++;
	}
	return (str);
}

t_tab	*init_tmp(t_tab *tmp, char **av, int i)
{
	tmp = (t_tab*)malloc(sizeof(t_tab));
	tmp->x = ft_atoi(av[i + 1]);
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

char	*raccourci_b(char *str, int *i)
{
	if (str[*i] == 'r' && str[*i + 3] == 'r' && str[*i - 1] != 'r')
	{
		if ((str[*i + 1] == 'a' && str[*i + 4] == 'b') ||
			(str[*i + 1] == 'b' && str[*i + 4] == 'a'))
		{
			(*i)++;
			str[*i] = 'r';
			str = fn_strchange(str, *i, 3);
		}
	}
	if (str[*i] == 'r' && str[*i + 1] == 'r' && str[*i + 4] == 'r' &&
		str[*i + 5] == 'r')
	{
		if ((str[*i + 2] == 'a' && str[*i + 6] == 'b') ||
			(str[*i + 2] == 'b' && str[*i + 6] == 'a'))
		{
			*i += 2;
			str[*i] = 'r';
			str = fn_strchange(str, *i, 4);
		}
	}
	return (str);
}
