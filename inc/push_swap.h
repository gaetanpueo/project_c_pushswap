/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:01:00 by gpueo--g          #+#    #+#             */
/*   Updated: 2015/03/08 15:01:03 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct			s_tab
{
	int					x;
	struct s_tab		*next;
	struct s_tab		*prev;
	struct s_tab		*deb;
}						t_tab;

t_tab					*fn_swap		(t_tab *tab);
char					*fn_tri			(t_tab *l_a, int flag);
t_tab					*fn_send		(t_tab **l_a, t_tab *l_b);
t_tab					*first_rot		(t_tab *tab);
t_tab					*last_rot		(t_tab *tab);
int						check_sort		(t_tab *tab);
int						ft_max			(t_tab *tab);
int						ft_min			(t_tab *tab);
t_tab					*creation		(t_tab *tab, int ac, char **av);
char					*raccourci		(char *str);
char					*fn_strchange	(char *str, int i, int n);
char					**decaler		(char **av);
char					*ft_strcolor	(char *str);
void					affiche			(t_tab *l_a, t_tab *l_b, char *str,
											int flag);
char					*delete_spaces	(char *str);
void					gest_error		(t_tab *tab);
void					affiche_a		(t_tab *l_a);
void					affiche_b		(t_tab *l_b);
t_tab					*fn_send_b		(t_tab *tab, t_tab *l_b);
t_tab					*init_tmp		(t_tab *tmp, char **av, int i);
char					*raccourci_b	(char *str, int *i);
char					**verif_flag	(int *ac, char **av, int *flag);
char					**flag_search	(int *flag, char **av);
t_tab					*fn_list_2		(t_tab *l_b, char **str, int *i,
											int *a);
t_tab					*fn_list_1		(t_tab *l_a, int *a, char **str);
t_tab					*fn_back		(t_tab *l_a, t_tab **l_b, char **str,
											int *i);
void					display			(int flag, t_tab *l_a, t_tab *l_b,
											char *str);
void					display_2		(int flag, char *str);
void					verif_num		(char **av);
t_tab					*fn_send_c		(t_tab *tab, t_tab *l_b);
t_tab					*creation_b		(t_tab *tmp2, t_tab *tmp);

#endif
