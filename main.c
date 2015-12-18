/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:42:08 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/18 17:24:20 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_sol_range(int **sol_tab)
{
	int i;
	int j;
	int range;

	range = 0;
	i = 0;
	j = 0;
	while (i < ft_count_pieces(sol_tab))
	{
		j = 0;
		while (j < 8)
		{
			if (sol_tab[i][j] > range)
				range = sol_tab[i][j];
			j++;
		}
		i++;
	}
	return (range);
}

char	**ft_convert(int **sol_tab)
{
	char	**tmp;
	int i;
	int j;
	int srange;
	char lettre;

	i = 0;
	j = 2;
	srange = ft_sol_range(sol_tab);
	lettre = 'A';
	tmp = (char **)ft_memalloc(sizeof(char *) * (srange + 1));
	while (i < ft_count_pieces(sol_tab))
	{
		tmp[i] = (char *)ft_memalloc(sizeof(char) * (srange + 1));
		tmp[i][srange] = '\n';
		tmp[sol_tab[i][0]][sol_tab[i][1]] = lettre;
		j = 2;
		while (j < 8)
		{
			tmp[sol_tab[j][0] + sol_tab[j][i]]
				[sol_tab[j][1] + sol_tab[j][i]] = lettre;
			j++;
		}
		lettre++;
	}
	tmp[srange][0] = '\0';
	return (tmp);
}

void	ft_display(int **sol_tab)
{
	int i;
	int j;
	char **tmp;

	i = 0;
	j = 0;
	tmp = ft_convert(sol_tab);
	while (tmp[i][0] != '\0')
	{
		while (tmp[i][j] != '\n')
		{
			ft_putchar(tmp[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
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


