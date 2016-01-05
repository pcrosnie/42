/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:49:57 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/05 15:11:31 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_noeud	*tree;

	g_info = (int *)malloc(sizeof(int) * 2);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		g_ref_tab = ft_get_tetriminos(fd);
		if (g_ref_tab)
		{
			g_info[0] = ft_count_pieces(g_ref_tab);
			g_info[1] = ft_search_range(g_info[0]);
			tree = ft_def_start_possible_position();
			ft_parkour(tree, 0);
			ft_display(ft_convert());
		}
	}
	else
		write(1, "error", 5);
	return (0);
}
