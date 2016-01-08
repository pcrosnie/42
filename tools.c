/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:25:33 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/08 18:31:06 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_intstrcpy(int *str)
{
	int	i;
	int	*str2;

	i = 0;
	str2 = (int *)malloc(sizeof(int) * 8);
	while (i < 8)
	{
		str2[i] = str[i];
		i++;
	}
	return (str2);
}

int		ft_strintstr(int *tmp, int *coord)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (tmp[i] == coord[j] && tmp[i + 1] == coord[j + 1])
		return (0);
	i = 2;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if ((tmp[0] + tmp[j] == coord[0] + coord[i])
					&& (tmp[1] + tmp[j + 1] == coord[1] + coord[i + 1]))
				return (0);
			if (tmp[0] + tmp[j] == coord[0] && tmp[1] + tmp[j + 1] == coord[1])
				return (0);
			if (coord[0] + coord[i] == tmp[0] &&
					coord[1] + coord[i + 1] == tmp[1])
				return (0);
			j += 2;
		}
		i += 2;
	}
	return (1);
}
