/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:30:07 by dgalide           #+#    #+#             */
/*   Updated: 2015/12/15 13:12:20 by pcrosnie         ###   ########.fr       */
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

int	**ft_get_tetriminos(char *argv, int fd)
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
	ft_memdel((void **)tab);
	if ((close(fd) != 0))
		return (0);
	return (coord);
}

void	ft_print_coord(int **tab, int nb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < nb)
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

int			main(int argc, char **argv)
{
	int fd;
	int c;
	int **coord;
	t_piece *lst;

	lst = NULL;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		coord = ft_get_tetriminos(argv[1], fd);
		ft_print_coord(coord, 5);
	}
	else
		ft_putstr("error");
	return (0);
}
