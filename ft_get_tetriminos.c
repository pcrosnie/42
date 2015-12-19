/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:58:37 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/19 18:47:23 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_buff_to_tab(char *buff)
{
	int i;
	int j;
	char **tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * 5);
	while (j < 4)
	{
		tab[j] = ft_strsub(&buff[i], 0, 5);
		j += 1;
		i += 5;
	}
	tab[j] = NULL;
	return (tab);
}

int	**ft_get_tetriminos(int fd)
{
	char	buffer[22];
	char	**tab;
	int	**coord;
	int	i;

	i = 0;
//    Initialisation a 26, on verra plus tard, ca dependra du nombre de piece pour l'allocation
	coord = (int **)malloc(sizeof(int *) * 26);
	while (read(fd, buffer, 21) && coord)
	{
		coord[i] = (int *)malloc(sizeof(int) * 8);
		if (!coord[i])
			return (0);
		tab = ft_buff_to_tab(buffer);
		if (ft_check_validity(tab) == 0)
			return (0);
		coord[i] = ft_fill_relative_coord(tab, coord[i]);
		i++;
	}
	coord[i] = NULL;
	ft_memdel((void **)tab);
	if ((close(fd) != 0))
		return (0);
	return (coord);
}

void	ft_print_coord(int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
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

void	ft_print_coord_piece(int *tab)
{
	int		i;

	i = 0;
	while (i < 8)
		ft_putnbr(tab[i++]);
}

/*int		main(int argc, char **argv)
{
	int fd;
	int i;
	t_noeud *tree;
	t_noeud *ptr;
	t_noeud	*ptr2;
	t_noeud *ptr3;

	tree = NULL;
	fd = 0;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ref_tab = ft_get_tetriminos(fd);
		if (ref_tab)
		{
			tree = ft_def_start_possible_position();
			while (tree->next[i] != NULL)
			{
				ft_print_coord_piece(tree->next[i++]->coord_piece);
				ft_putchar('\n');
			}
			ft_putstr("Second :\n");
			ptr = tree;
			ptr = tree->next[0];
			ft_fill_next(ptr, ft_search_range(ft_count_pieces(ref_tab)));
			ptr->prev = tree;
			i = 0;
			while (ptr->next[i] != NULL)
			{
				ft_print_coord_piece(ptr->next[i++]->coord_piece);
				ft_putchar('\n');
			}
			ptr2 = ptr->next[0];
			ft_fill_next(ptr2, ft_search_range(ft_count_pieces(ref_tab)));
			i = 0;
			ft_putstr("Third :\n");
			while (ptr2->next[i] != NULL)
			{
				ft_print_coord_piece(ptr2->next[i++]->coord_piece);
				ft_putchar('\n');
			}
			ptr3 = ptr2->next[0];
			ft_fill_next(ptr3, ft_search_range(ft_count_pieces(ref_tab)));
			i = 0;
			ft_putstr("Fourth :\n");
			while (ptr3->next[i] != NULL)
			{
				ft_print_coord_piece(ptr3->next[i++]->coord_piece);
				ft_putchar('\n');
			}
			ft_putchar('\n');
			ft_fill_sol_tab(ptr3->next[0]);
			ft_display(ft_convert(sol_tab));
			ft_putchar('\n');
		}
		if (!ref_tab)
		{
			ft_putstr("error");
			return (0);
		}
	}
	return (0);
}*/

