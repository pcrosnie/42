/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 12:09:07 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/18 15:59:41 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_end(t_noeud *ptr)
{
	int i;
	t_noeud *ptr2;

	i = 0;
	ptr2 = ptr->prev;
	while (ptr2 != NULL)
	{
		i++;
		if (ptr != ptr2->next[ptr2->next_max])
			return (0);
		ptr = ptr2;
		ptr2 = ptr2->prev;
	}
	return (1);
}

void	ft_free_node(t_noeud *ptr)
{
	int		i;

	i = 0;
	while (ptr->next == NULL && i < ptr->next_max)
	{
		i++;
	}
	free(ptr->next[i]->coord_piece);
	free(ptr->next[i]->next);
	free(ptr->next[i]);
}

void	ft_solve(t_noeud *ptr)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (ft_check_end(ptr) != 1 && ft_check_sol(ptr) != 1)
	{
		ft_fill_next(ptr, ft_search_range(ft_count_pieces(ref_tab)));
		if (ptr->etape == ft_count_pieces(ref_tab))
		{
			if (ft_check_sol(ptr) == 1)
				ft_fill_sol_tab(ptr);
			else if (ft_check_sol(ptr) == 0 && n == 0)
			{
				ft_fill_sol_tab(ptr);
				n = 1;
			}
		}
		i = 0;
		if (ptr->next_max > 1)
		{
			while (ptr->next == NULL && i < ptr->next_max - 1)
				i++;
			ptr = ptr->next[i];
		}
		else
		{
			ptr = ptr->prev;
			ft_free_node(ptr);
		}
	}
}

int		main(int argc, char **argv)
{
	t_noeud	*ptr;
	int		fd;
	int		i;

	fd = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	ref_tab = ft_get_tetriminos(fd);
	if (ref_tab)
	{
		ptr = ft_def_start_possible_position();
		ft_putchar('1');
		ft_solve(ptr);
		ft_putchar('2');
		while (i < 4)
		{
			ft_putchar('3');
			ft_print_coord_piece(sol_tab[i++]);
		}
	}
	return (0);
}
