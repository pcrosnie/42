/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:42:15 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/11 17:24:46 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_pieces(t_piece **adr)
{
	int	i;
	t_piece *ptr;

	i = 0;
	ptr = *adr;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int		*ft_fill_relative_coord(char **tab, int *str)
{
	int i;
	int j;
	int k;
	int	n;

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
	return (str);
}

/*
int		*ft_fill_coord(char **tab, int	*str)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				str[k] = j;
				str[k + 1] = i;
				k += 2;
			}
			j++;
		}
		i++;
	}
	return (str);
}
*/
int		**ft_get_coord(t_piece **adr)
{
	t_piece *ptr;
	int **tab;
	int j;
	int	i;

	i = 0;
	j = 0;
	ptr = *adr;
	tab = (int **)malloc(sizeof(int *) * ft_count_pieces(adr));
	while (ptr != NULL)
	{
		tab[i] = (int *)malloc(sizeof(int) * 8);
		tab[i] = ft_fill_relative_coord(ptr->piece, tab[i]);
		j = 0;
		ptr = ptr->next;
		i++;
	}
	return (tab);
}

void	ft_print_coord(int **tab, t_piece **adr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_count_pieces(adr))
	{
		j = 0;
		while (j < 8)
		{
			ft_putnbr(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/*
   int		main()
   {
   t_piece *ptr;
   t_piece *ptr2;
   t_piece *ptr3;
   int	i;
   int j;
   j = 0;
   i = 0;

   ptr = (t_piece *)malloc(sizeof(t_piece));
   ptr->piece = (char **)malloc(sizeof(char *) * 5);
   ptr->piece[0] = "....\0";
   ptr->piece[1] = ".##.\0";
   ptr->piece[2] = ".##.\0";
   ptr->piece[3] = "....\0";
   ptr->piece[4] = NULL;
   ptr2 = (t_piece *)malloc(sizeof(t_piece));
   ptr2->piece = (char **)malloc(sizeof(char *) * 5);
   ptr2->piece[0] = "....\0";
   ptr2->piece[1] = ".###\0";
   ptr2->piece[2] = ".#..\0";
   ptr2->piece[3] = "....\0";
   ptr2->piece[4] = NULL;
   ptr2->next = NULL;
   ptr->next = ptr2;
   ptr3 = (t_piece *)malloc(sizeof(t_piece));
   ptr3->piece = (char **)malloc(sizeof(char *) * 5);
   ptr3->piece[0] = ".###\0";
   ptr3->piece[1] = "...#\0";
   ptr3->piece[2] = "....\0";
   ptr3->piece[3] = "....\0";
   ptr3->piece[4] = NULL;
   ptr3->next = NULL;
   ptr2->next = ptr3;
   if (ft_check_validity(ptr) == 1 && ft_check_validity(ptr2) == 1 && ft_check_validity(ptr3) == 1)
   ft_get_coord(&ptr);
   else
   ft_putstr("Non valide");
   return (0);
   }
   */
