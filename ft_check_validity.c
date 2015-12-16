/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:53:23 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/16 15:33:26 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_t(char **tab, int i, int j)
{
	int n;
	
	n = 0;
	if (i < 3)
	{
		if (tab[i + 1][j] == '#')
			n++;
	}
	if (i > 0)
	{
		if (tab[i - 1][j] == '#')
		{
			n++;
		}
	}
	if (j < 3)
	{
		if (tab[i][j + 1] == '#')
			n++;
	}
	if (j > 0)
	{	
		if (tab[i][j - 1] == '#')
			n++;
	}
	if (n > 1)
		return (1);
	return (0);
}

int     ft_check_glue(char **tab, int i, int j, int *tmp)
{
	if (ft_check_t(tab, tmp[0], tmp[1]) == 1)
		return (1);
	if (i < 3)
	{
		if (tab[i + 1][j] == '#' && (tmp[0] != i + 1 || tmp[1] != j))
			return (1);
	}
	if (i > 0)
	{
		if (tab[i - 1][j] == '#' && (tmp[0] != i - 1 || tmp[1] != j))
			return (1);
	}
	if (j < 3)
	{
		if (tab[i][j + 1] == '#' && (tmp[0] != i || tmp[1] != j + 1))
			return (1);
	}
	if (j > 0)
	{
		if (tab[i][j - 1] == '#' && (tmp[0] != i || tmp[1] != j - 1))
			return (1);
	}
	return (0);
}

int		ft_check_tetraminos(char **tab, int i, int j)
{
	int *tmp;

	tmp = (int *)malloc(sizeof(int) * 2);
	tmp[0] = i;
	tmp[1] = j;
	if (i < 3)
	{
		if (tab[i + 1][j] == '#' && ft_check_glue(tab, i + 1, j, tmp) == 1)
			return (1);
	}
	if (i > 0)
	{
		if (tab[i - 1][j] == '#' && ft_check_glue(tab, i - 1, j, tmp) == 1)
			return (1);
	}
	if (j < 3)
	{
		if (tab[i][j + 1] == '#' && ft_check_glue(tab, i, j + 1, tmp) == 1)
			return (1);
	}
	if (j > 0)
	{
		if (tab[i][j - 1] == '#' && ft_check_glue(tab, i, j - 1, tmp) == 1)
			return (1);
	}
	return (0);
}

int		ft_check_validity(char **tab)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && (tab[i][j] == '.' || tab[i][j] == '#'))
		{
			if (tab[i][j++] == '#')
			{
				if (ft_check_tetraminos(tab, i, j - 1) == 0 || j > 4 || n > 4)
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
