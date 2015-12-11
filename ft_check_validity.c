/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:53:23 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/11 16:41:08 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_tetraminos(t_piece *ptr, int i, int j)
{
	if (ptr->piece[i + 1])
	{
		if (ptr->piece[i + 1][j] == '#')
			return (1);
	}
	if (ptr->piece[i - 1])
	{
		if (ptr->piece[i - 1][j] == '#')
			return (1);
	}
	if (ptr->piece[i][j + 1])
	{
		if (ptr->piece[i][j + 1] == '#')
			return (1);
	}
	if (ptr->piece[i][j - 1])
	{
		if (ptr->piece[i][j - 1] == '#')
			return (1);
	}
	return (0);
}

int		ft_check_validity(t_piece *ptr)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (ptr->piece[i])
	{
		j = 0;
		while (ptr->piece[i][j] && (ptr->piece[i][j] == '.' || ptr->piece[i][j] == '#'))
		{
			if (ptr->piece[i][j++] == '#')
			{
				if (ft_check_tetraminos(ptr, i, j - 1) == 0 || j > 4 || n > 4)
					return (0);
				n++;
			}
		}
		if (j != 4)
			return (0);
		i++;
	}
	if (n != 4 || i != 4)
		return (0);
	return (1);
}

/*
   int		main()
   {
   t_piece		*ptr;
   int	i;
   i = 0;

   ptr = (t_piece *)malloc(sizeof(t_piece));
   ptr->piece = (char **)malloc(sizeof(char *) * 5);
   ptr->piece[0] = ".#..";
   ptr->piece[1] = "###.";
   ptr->piece[2] = "....";
   ptr->piece[3] = "....";
   ptr->piece[4] = NULL;
   ft_putnbr(ft_check_validity(ptr));
   ft_putchar('\n');
   return (0);
   }

*/
