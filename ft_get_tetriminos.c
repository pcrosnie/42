/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:30:07 by dgalide           #+#    #+#             */
/*   Updated: 2015/12/11 17:24:41 by pcrosnie         ###   ########.fr       */
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
		tab[j] = ft_strsub(&buff[i], 0, 4);
		j += 1;
		i += 5;
	}
	tab[j] = NULL;
	return (tab);
}

t_piece		*ft_lst_newi(char **content, int split)
{
	t_piece *new;

	new = (t_piece *)malloc(sizeof(t_piece));
	if (new)
	{
		new->piece = content;
		new->split = split;
		new->next = NULL;
		return (new);
	}
	else
		return (NULL);
}

void		ft_lst_push_back(t_piece **lst, char **content, int c)
{
	t_piece *tmp;

	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lst_newi(content, c);
	}
	else
		*lst = ft_lst_newi(content, c);
}

void		ft_make_circulary(t_piece **lst)
{
	t_piece *tmp;

	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = NULL;
	}
}

int			ft_get_tetriminos(int fd, t_piece **lst)
{
	char	buffer[22];
	char	**tab;
	char	c;

	c = 'A';
	while (read(fd, buffer, 21))
	{
		tab = ft_buff_to_tab(buffer);
		ft_lst_push_back(lst, tab, c);
		c++;
	}
	ft_make_circulary(lst);
	return (c);
}

void		ft_print_list(t_piece **lst, int c)
{
	t_piece *tmp;
	int		i;

	tmp = *lst;
	i = 1;
	while (i < c && tmp)
	{
		ft_putchar(tmp->split);
		ft_putchar('\n');
		ft_print_char_tab(tmp->piece);
		ft_putchar('\n');

		i++;
		tmp = tmp->next;
	}
}

int		ft_check_map(t_piece **adr)
{
	t_piece *ptr;

	ptr = *adr;
	while (ptr != NULL)
	{
		if (ft_check_validity(ptr) == 0)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int fd;
	int c;
	t_piece *lst;

	lst = NULL;
	fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	c = ft_get_tetriminos(fd, &lst);
	if (ft_check_map(&lst) == 1)
	{
		ft_print_list(&lst, c);
		ft_print_coord(ft_get_coord(&lst), &lst);
	}	
	else
		ft_putstr("error");
	return (0);
}
