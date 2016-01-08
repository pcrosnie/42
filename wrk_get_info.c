/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrk_get_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:34:00 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/08 18:36:20 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_search_range(int n)
{
	int	i;

	i = 1;
	while ((i * i) < (n * 4))
		i++;
	if (i < 4)
		i = 4;
	return (i + 1);
}

int		ft_count_pieces(int **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
