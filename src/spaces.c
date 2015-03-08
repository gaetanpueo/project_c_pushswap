/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:01:12 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/08 15:01:15 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	*delete_spaces(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (str[i] == ' ')
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

char	*fn_strchange(char *str, int i, int n)
{
	int		x;
	int		j;

	x = 0;
	while (x < n)
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			str[j] = str[j + 1];
			j++;
		}
		x++;
	}
	return (str);
}

char	**decaler(char **av)
{
	int		i;

	i = 1;
	while (av[i + 1])
	{
		av[i] = ft_strdup(av[i + 1]);
		i++;
	}
	av[i] = NULL;
	return (av);
}
