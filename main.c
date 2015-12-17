/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:42:08 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/17 17:21:09 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_parkour(t_noeud *tree, int i)
{
	if (tree->etape == ft_count_pieces(ref_tab))
		if (ft_check_sol(tree) == 0)
			// range max, stockage dans sol_tab;
		else if (ft_check_sol(tree) == 1)
			// range min, display;
	ft_fill_next(tree, ft_search_range(ft_count_pieces(ref_tab)));
	while (tree->next[i]
}

int		main(int argc, char **argv)
{
	int fd;
	t_noeud *tree;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ref_tab = ft_get_tetriminos(fd);
		if (ref_tab)
		{
			tree = ft_def_start_possible_position();
			ft_parkour(tree, 0);
		}
	}
	else
		write(1, "error", 5);
}


