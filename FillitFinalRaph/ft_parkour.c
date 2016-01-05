/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:42:08 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/05 17:50:02 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_sol_range()
{
	int nbp;
	int i;
	int range;

	range = 0;
	i = 0;
	nbp = 0;
	while (nbp < g_info[0])
	{
		i = 0;
		while (i < 6)
		{
			if ((g_sol_tab[nbp][0] + g_sol_tab[nbp][i + 2]) > range)
				range = (g_sol_tab[nbp][0] + g_sol_tab[nbp][i + 2]);
			i++;
			if ((g_sol_tab[nbp][1] + g_sol_tab[nbp][i + 2]) > range)
				range = (g_sol_tab[nbp][1] + g_sol_tab[nbp][i + 2]);
			i++;
		}
		nbp++;
	}
	return (range + 1);
}

char	**ft_convert()
{
	char	**tmp;
	int i;
	int j;
	int srange;
	char lettre;

	i = 0;
	j = 2;
	srange = ft_sol_range();
	lettre = 'A';
	tmp = ft_newc2d(srange, srange, '.');
	i = 0;
	while (i < g_info[0])
	{
		tmp[g_sol_tab[i][1]][g_sol_tab[i][0]] = lettre;
		j = 2;
		while (j < 8)
		{
			tmp[g_sol_tab[i][j + 1] + g_sol_tab[i][1]]
				[g_sol_tab[i][j] + g_sol_tab[i][0]] = lettre;
			j += 2;
		}
		i++;
		lettre++;
	}
	return (tmp);
}

void	ft_display(char **tab)
{
	int i;
	int j;
	int		srange;

	i = 0;
	j = 0;
	srange = ft_sol_range();
	while (i < srange)
	{
		while (j < srange)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	exit(0);
}

void	ft_parkour(t_noeud *tree, int i)
{
	int	sol_range;
	if (tree->etape == g_info[0])
	{
			sol_range = ft_check_sol(tree);
			if (sol_range == 0 && g_sol_tab == NULL)
			{
				ft_putstr("\nSOLUTION RANGE MAX : \n\n");
				ft_fill_sol_tab(tree);
			}
			else if (sol_range == 1)
			{
				ft_putstr("\nSOLUTION RANGE MIN : \n\n");
				ft_fill_sol_tab(tree);
				ft_display(ft_convert());
			}
	}
	else if (tree->etape != 0)
	{
		if (g_sol_tab == NULL)
			ft_fill_next(tree, g_info[1]);
		else
			ft_fill_next(tree, g_info[1] - 1);
	}
	while (tree->next[i])
	{
		ft_parkour(tree->next[i], 0);
		i++;
	}
}
