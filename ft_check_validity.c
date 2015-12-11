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

int	ft_check_t(t_piece *ptr, int i, int j)
{
	int n;
	
	n = 0;
	if (ptr->piece[i + 1] && ptr->piece[i + 1][j] == '#')
		n++;
	if (ptr->piece[i - 1] && ptr->piece[i - 1][j] == '#')
		n++;
	if (ptr->piece[i][j + 1] && ptr->piece[i][j + 1] == '#')
		n++;
	if (ptr->piece[i][j - 1] && ptr->piece[i][j - 1] == '#')
		n++;
	if (n > 1)
		return (1);
	return (0);
}

int     ft_check_glue(t_piece *ptr, int i, int j, int *tmp)
{
	if (ft_check_t(ptr, tmp[0], tmp[1]) == 1)
		return (1);
	if (ptr->piece[i + 1])
	{
		if (ptr->piece[i + 1][j] == '#' && (tmp[0] != i + 1 || tmp[1] != j))
			return (1);
	}
	if (ptr->piece[i - 1])
	{
		if (ptr->piece[i - 1][j] == '#' && (tmp[0] != i - 1 || tmp[1] != j))
			return (1);
	}
	if (ptr->piece[i][j + 1])
	{
		if (ptr->piece[i][j + 1] == '#' && (tmp[0] != i || tmp[1] != j + 1))
			return (1);
	}
	if (ptr->piece[i][j - 1])
	{
		if (ptr->piece[i][j - 1] == '#' && (tmp[0] != i || tmp[1] != j - 1))
			return (1);
	}
	return (0);
}

int		ft_check_tetraminos(t_piece *ptr, int i, int j)
{
	int *tmp;

	tmp = (int *)malloc(sizeof(int) * 2);
	tmp[0] = i;
	tmp[1] = j;
	if (ptr->piece[i + 1])
	{
		if (ptr->piece[i + 1][j] == '#' && ft_check_glue(ptr, i + 1, j, tmp) == 1)
			return (1);
	}
	if (ptr->piece[i - 1])
	{
		if (ptr->piece[i - 1][j] == '#' && ft_check_glue(ptr, i - 1, j, tmp) == 1)
			return (1);
	}
	if (ptr->piece[i][j + 1])
	{
		if (ptr->piece[i][j + 1] == '#' && ft_check_glue(ptr, i, j + 1, tmp) == 1)
			return (1);
	}
	if (ptr->piece[i][j - 1])
	{
		if (ptr->piece[i][j - 1] == '#' && ft_check_glue(ptr, i, j - 1, tmp) == 1)
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
