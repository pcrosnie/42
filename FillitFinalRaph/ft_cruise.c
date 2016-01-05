/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cruise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:56:51 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/05 16:11:41 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill_sol_tab(t_noeud *ptr)
{
	int	i;

	i = g_info[0] - 1;
	g_sol_tab = (int **)malloc(sizeof(int *) * i);
	while (i >= 0)
	{
		g_sol_tab[i] = (int *)malloc(sizeof(int) * 8);
		g_sol_tab[i] = ft_intstrcpy(ptr->coord_piece);
		i--;
		ptr = ptr->prev;
	}
	g_sol_tab[g_info[0]] = NULL;
}

int		*ft_set_tab_vertical(int n)
{
	int *tab;
	int i;
	int j;

	i = 2;
	j = 1;
	tab = (int *)malloc(sizeof(int) * (n * 2));
	tab[0] = n - 1;
	tab[1] = 0;
	while (i < (n * 2))
	{
		tab[i] = 0;
		tab[i + 1] = j++;
		i += 2;
	}
	return (tab);
}

int		*ft_set_horizontal(int n)
{
	int	*tab;
	int i;
	int j;

	i = 2;
	j = 1;
	tab = (int *)malloc(sizeof(int) * (n * 2));
	tab[0] = 0;
	tab[1] = n - 1;
	while (i < (n * 2))
	{
		tab[i] = j++;
		tab[i + 1] = 0;
		i += 2;
	}
	return (tab);
}

int		ft_check_for_range_max(int *tab, int *str, int n)
{
	int	i;
	int j;

	i = 2;
	j = 0;
	if (tab[0] == str[0] && tab[1] == str[1])
		return (0);
	while (i < n * 2)
	{
		j = 2;
		while (j < 8)
		{
			if (tab[0] + tab[i] == str[0] + str[j] && tab[1] + tab[i + 1] == str[1] + str[j + 1])
				return (0);
			if (tab[0] == str[0] + str[j] && tab[1] == str[1] + str[j + 1])
				return (0);
			if (str[0] == tab[0] + tab[i] && str[1] == tab[1] + tab[i + 1])
				return (0);
			j += 2;
		}
		i += 2;
	}
	return (1);
}

int		ft_check_sol(t_noeud *ptr)
{
	int		n;
	int 	*Vert_tab;
	int		*Hor_tab;

	n = g_info[1];
	Vert_tab = ft_set_tab_vertical(n);
	Hor_tab = ft_set_horizontal(n);
	while (ptr != NULL)
	{	
		if (ft_check_for_range_max(Vert_tab, ptr->coord_piece, n) == 0
				|| ft_check_for_range_max(Hor_tab, ptr->coord_piece, n) == 0)
			return (0);
		ptr = ptr->prev;
	}
	return (1);
}
