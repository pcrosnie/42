/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:58:37 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/06 16:46:23 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_count_pieces(int **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			*ft_fill_relative_coord(char **tab, int *str)
{
	int		i;
	int		j;
	int		k;
	int		n;

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

char		**ft_fill_ref_tab(char *buff)
{
	int i;
	int j;
	char **tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * 5);
	while (j < 4)
	{
		tab[j] = ft_strsub(&buff[i], 0, 5);
		j++;
		i += 5;
	}
	tab[j] = NULL;
	return (tab);
}

int	**ft_get_tetriminos(int fd)
{
	char	buffer[22];
	char	**tab;
	int	**coord;
	int	i;

	i = 0;
	coord = (int **)malloc(sizeof(int *) * 27);
	while (read(fd, buffer, 21) && coord)
	{
		coord[i] = (int *)malloc(sizeof(int) * 8);
		if (!coord[i])
			return (0);
		tab = ft_fill_ref_tab(buffer);
		if (ft_check_validity(tab) == 0)
			return (0);
		coord[i] = ft_fill_relative_coord(tab, coord[i]);
		i++;
	}
	coord[i] = NULL;
	ft_memdel((void **)tab);
	if ((close(fd) != 0))
		return (0);
	return (coord);
}
