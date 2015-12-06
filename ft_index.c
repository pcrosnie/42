/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 19:58:06 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/06 23:22:12 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_count_for_sort(t_piece *ptr)
{
	int		i;
	int		j;
	int		k;
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 100);
	while (j < 4)
	{
		i = 0;
		k = 0;
		while (i < 4)
		{
		//	ft_putchar('A');
			if (ptr->piece[i++][j] == '#')
			{
//				ft_putchar('A');
				k++;
			}
		}
	//	ft_putnbr(k);
		tab[j++] = k;
	}
	i = 0;
//	while (i < 8)
//		ft_putnbr(tab[i++]);
//	ft_putchar('\n');
//	i = 0;
	while (i < 4)
	{
		j = 0;
		k = 0;
		while (j < 4)
		{
			if (ptr->piece[i][j++] == '#')
			{
			//	ft_putchar('A');
				k++;
			}
		}
		tab[i++ + 4] = k;
	}
//	i = 0;
//	while (i < 8)
//		ft_putnbr(tab[i++]);
//	ft_putchar('\n');
	return (tab);
}
