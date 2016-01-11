/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:58:37 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/11 18:46:13 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*ft_fill_fst_ptr(int *str, int i, int j)
{
	str[0] = j;
	str[1] = i;
	return (str);
}

int			*ft_fill_relative_coord(char **tab, int *str, int n, int k)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#' && n++ == 0)
				str = ft_fill_fst_ptr(str, i, j);
			else if (tab[i][j] == '#' && n != 0)
			{
				str[k++] = j - str[0];
				str[k++] = i - str[1];
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
	int		i;
	int		j;
	char	**tab;

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

int			**ft_get_tetriminos(int fd)
{
	char	buffer[22];
	char	**tab;
	int		**coord;
	int		i;

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
		coord[i] = ft_fill_relative_coord(tab, coord[i], 0, 2);
		i++;
	}
	coord[i] = NULL;
	ft_memdel((void **)tab);
	if ((close(fd) != 0) || coord[0] == NULL)
		return (0);
	return (coord);
}
