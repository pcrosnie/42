/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_for_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:24:22 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/07 17:44:47 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_for_two(t_piece *ptr)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (ptr->piece[i][j] == '#' && ptr->piece[i + 1][j + 1] == '#')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_count_for_sort_part2(t_piece *ptr)
{
	char *tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	tab = (char *)malloc(sizeof(char) * 5);
	while (i < 4)
	{
		j = 0;
		k = 0;
		while (j < 4)
		{
			if (ptr->piece[i][j++] == '#')
				k++;
		}
		tab[i++] = k + 48;
	}
	tab[i] = '\0';
	return (tab);
}
char	*ft_count_for_sort(t_piece *ptr)
{
	int		i;
	int		j;
	int		k;
	char	*tab;

	j = 0;
	tab = (char*)malloc(sizeof(char) * 5);
	while (j < 4)
	{
		i = 0;
		k = 0;
		while (i < 4)
		{
			if (ptr->piece[i++][j] == '#')
				k++;
		}
		tab[j++] = k + 48;
	}
	tab[j] = '\0';
	tab = ft_strjoin(tab, ft_count_for_sort_part2(ptr));
	return (tab);
}
