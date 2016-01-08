/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:45:14 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/08 18:46:05 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

int		**g_ref_tab;
int		**g_sol_tab;
int		*g_info;

typedef struct		s_noeud
{
	int				*coord_piece;
	int				etape;
	int				*next_max;
	struct s_noeud	**next;
	struct s_noeud	*prev;
}					t_noeud;

int					ft_check_validity(char **tab);
int					ft_check_tetraminos(char **tab, int i, int j);
int					ft_check_glue(char **tab, int i, int j, int *tmp);
int					ft_check_t(char **tab, int i, int j);

int					**ft_get_tetriminos(int fd);
char				**ft_fill_ref_tab(char *buff);
int					*ft_fill_relative_coord(char **tab, int *str);
int					ft_count_pieces(int **tab);

t_noeud				*ft_def_start_possible_position();
int					ft_search_range(int n);
int					*ft_intstrcpy(int *str);
int					ft_check_limits(int *tab, int n);
int					ft_strintstr(int *tmp, int *coord);
int					ft_check_overlap(int *tmp, t_noeud *ptr);
struct s_noeud		*ft_fill_next_ptr(int *tmp, int nb, t_noeud *adr);
void				ft_fill_next(t_noeud *ptr, int nb);

int					ft_check_sol(t_noeud *ptr);
void				ft_fill_sol_tab(t_noeud *ptr);
int					*ft_set_tab_vertical(int n);
int					*ft_set_horizontal(int n);
int					ft_check_for_range_max(int *tab, int *str, int n);

void				ft_parkour(t_noeud *tree, int i);
void				ft_display(char **tab);
int					ft_sol_range();
char				**ft_convert();

#endif
