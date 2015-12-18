/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 12:09:07 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/18 17:17:08 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_end(t_noeud *ptr)
{
	if (ptr->prev == NULL && ptr->next_max[0] == ptr->next_max[1])
			return (1);
	return (0);
}

void	ft_free_node(t_noeud *ptr)
{
	int		i;

	i = ptr->next_max[0];
	while (i < ptr->next_max[1])
		i++;
	free(ptr->next[i]->coord_piece);
	free(ptr->next[i]->next);
	ptr->next[i] = NULL;
}

void	ft_solve(t_noeud *ptr)
{
	int n;
	int i;

	n = 0;
	i = 0;
	ft_putnbr(ft_check_sol(ptr));
	while (ft_check_end(ptr) != 1 && ft_check_sol(ptr) != 1)
	{

		if (ptr->next_max[0] < ptr->next_max[1])
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
			ft_putchar('A');
		}
		i = ptr->next_max[0]++;
		if (i < ptr->next_max[1])
			ptr = ptr->next[i];
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
		ft_solve(ptr);
		if (!sol_tab)
			return (0);
		while (i < 4)
		{
			ft_putchar('3');
			ft_print_coord_piece(sol_tab[i++]);
		}
	}
	return (0);
}
