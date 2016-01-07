/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reserve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:57:26 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/07 12:07:15 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_intstrcpy(int *str)
{
	int i;
	int *str2;

	i = 0;
	str2 = (int *)malloc(sizeof(int) * 8);
	while (i < 8)
	{
		str2[i] = str[i];
		i++;
	}
	return (str2);
}

int		ft_search_range(int n)
{
	int i;

	i = 1;
	while ((i * i) < (n * 4))
		i++;
	if (i < 4)
		i = 4;
	return (i + 1);
}

int		ft_check_limits(int *tab, int n)
{
	n = n - 1;
	if ((tab[0] + tab[2] > n) || (tab[1] + tab[3] > n))
		return (0);
	if ((tab[0] + tab[2] < 0) || (tab[1] + tab[3] < 0))
		return (0);
	if ((tab[0] + tab[4] > n) || (tab[1] + tab[5] > n))
		return (0);
	if ((tab[0] + tab[4] < 0) || (tab[1] + tab[5] < 0))
		return (0);
	if ((tab[0] + tab[6] > n) || (tab[1] + tab[7] > n))
		return (0);
	if ((tab[0] + tab[6] < 0) || (tab[1] + tab[7] < 0))
		return (0);
	return (1);
}
