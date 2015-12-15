/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:45:14 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/15 14:57:13 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

int		**ref_tab;

typedef struct	s_piece
{
	char	**piece;
	char	split;
	struct s_piece	*next;
}				t_piece;

typedef struct	s_noeud
{
	int	*coord_piece;
	int	etape;
	struct s_noeud **next;
	struct s_noeud *prev;
}				t_noeud;

int	ft_count_pieces(t_piece **adr);
int		**ft_get_coord(t_piece **adr);
void	ft_print_coord(int **tab, int nb);
char	**ft_buff_to_tab(char *buff);
int	**ft_get_tetriminos(char *argv, int fd);
int		ft_check_validity(char **tab);
char	*ft_count_for_sort(t_piece *ptr);
void	ft_index(t_piece *ptr);
int		ft_check_for_two(t_piece *ptr);
void	ft_lst_push_back(t_piece **lst, char **content, int c);
void	ft_print_list(t_piece **lst, int c);
int	*ft_fill_relative_coord(char **tab, int *str);
t_piece	*ft_lst_newi(char **content, int split);

#endif
