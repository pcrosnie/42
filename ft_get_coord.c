/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:42:15 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/15 15:49:22 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_pieces(int **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		*ft_fill_relative_coord(char **tab, int *str)
{
	int i;
	int j;
	int k;
	int	n;

	i = 0;
	k = 2;
	n = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#' && n == 0)
			{
				str[0] = j;
				str[1] = i;
				n = 1;
			}
			else if (tab[i][j] == '#' && n != 0)
			{
				str[k] = j - str[0];
				str[k + 1] = i - str[1];
				k += 2;
			}
			j++;
		}
		i++;
	}
	str[0] = 0;
	str[1] = 0;
	return (str);
}

int		**ft_get_coord(t_piece **adr)
{
	t_piece *ptr;
	int **tab;
	int j;
	int	i;

	i = 0;
	j = 0;
	ptr = *adr;
	tab = (int **)malloc(sizeof(int *) * ft_count_pieces(ref_tab));
	while (ptr != NULL)
	{
		tab[i] = (int *)malloc(sizeof(int) * 8);
		tab[i] = ft_fill_relative_coord(ptr->piece, tab[i]);
		j = 0;
		ptr = ptr->next;
		i++;
	}
	return (tab);
}
