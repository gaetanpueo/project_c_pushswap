/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:01:12 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/08 15:01:15 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	**verif_flag(int *ac, char **av, int *flag)
{
	*flag = 0;
	if (av[1][0] == '-')
	{
		if (ft_isalpha(av[1][1]))
		{
			(*ac)--;
			av = flag_search(flag, av);
		}
		else if (!ft_isdigit(av[1][1]))
		{
			ft_putendl(C_RED"Error");
			exit(1);
		}
	}
	else if (!ft_isdigit(av[1][0]))
	{
		ft_putendl(C_RED"Error");
		exit(1);
	}
	return (av);
}

char	**flag_search(int *flag, char **av)
{
	if (ft_strcmp(av[1], "-c") == 0)
		*flag = 1;
	else if (ft_strcmp(av[1], "-v") == 0)
		*flag = 2;
	else if (ft_strcmp(av[1], "-cv") == 0 || ft_strcmp(av[1], "-vc") == 0)
		*flag = 3;
	else
	{
		ft_putendl(C_RED"Error");
		exit(1);
	}
	av = decaler(av);
	return (av);
}