/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:42:08 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/17 19:49:32 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_sol_range(int **sol_tab)
{

}

char	**ft_convert(int **sol_tab)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * ft_sol_range(sol_tab));

}

void	ft_display(int **sol_tab)
{
	int i;
	char lettre;
	char **tmp;

	i = 0;
	lettre = 'A';
	tmp = ft_convert(sol_tab);
	while (i < ft_count_pieces(ref_tab))
	{
		ft_putstr(tmp[i]);
		i++;
	}
}

void	ft_parkour(t_noeud *tree, int i)
{
	if (tree->etape == ft_count_pieces(ref_tab))
	{
		if ((ft_check_sol(tree) == 0) && sol_tab == NULL)
			ft_fill_sol_tab(tree);
		else if (ft_check_sol(tree) == 1)
		{
			ft_fill_sol_tab(tree);
			ft_display(sol_tab);
		}
	}
	else
		ft_fill_next(tree, ft_search_range(ft_count_pieces(ref_tab)));
	while (tree->next[i])
	{
		ft_parkour(tree->next[i], 0);
		i++;
	}
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


