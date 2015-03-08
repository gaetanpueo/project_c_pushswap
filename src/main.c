/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:01:12 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/08 15:01:15 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	t_tab	*tab;
	char	*str;
	int		flag;

	if (ac == 1)
		return (1);
	ac--;
	tab = NULL;
	av = verif_flag(&ac, av, &flag);
	tab = creation(tab, ac, av);
	gest_error(tab);
	if (check_sort(tab))
	{
		ft_putendl(C_GREEN"Liste déja trier !");
		return (1);
	}
	str = fn_tri(tab, flag);
	str = raccourci(str);
	str = delete_spaces(str);
	display_2(flag, str);
	free(str);
	return (0);
}
