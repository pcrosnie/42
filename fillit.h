/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:45:14 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/18 14:18:34 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

int		**ref_tab;
int		**sol_tab;

typedef struct		s_noeud
{
	int				*coord_piece;
	int				etape;
	int				next_max;
	struct s_noeud	**next;
	struct s_noeud	*prev;
}					t_noeud;

// ft_check_validity.c
int					ft_check_validity(char **tab); // globale
int					ft_check_tetraminos(char **tab, int i, int j); // static
int					ft_check_glue(char **tab, int i, int j, int *tmp); // static
int					ft_check_t(char **tab, int i, int j); // static

// ft_get_coord.c
int					*ft_fill_relative_coord(char **tab, int *str); // globale
int					ft_count_pieces(int **tab); // globale

// ft_get_tetriminos.c
int					**ft_get_tetriminos(int fd); // globale
char				**ft_buff_to_tab(char *buff); // static
void				ft_print_coord(int **tab); // static
void				ft_print_coord_piece(int *tab); // static

// ft_search_range.c
t_noeud				*ft_def_start_possible_position(); // globale
int					ft_search_range(int n); // static
int					*ft_intstrcpy(int *str); // static
int					ft_check_limits(int *tab, int n); // static
int					ft_strintstr(int *tmp, int *coord); // static
int					ft_check_overlap(int *tmp, t_noeud *ptr); // static
struct s_noeud		*ft_fill_next_ptr(int *tmp, int nb, t_noeud *adr); // static
void				ft_fill_next(t_noeud *ptr, int nb); // static

// ft_cruise.c
int					ft_check_sol(t_noeud *ptr);
void				ft_fill_sol_tab(t_noeud *ptr);
int					*ft_set_tab_vertical(int n);
int					*ft_set_horizontal(int n);
int					ft_check_for_range_max(int *tab, int *str, int n);

// ft_solve.c
int					ft_check_end(t_noeud *ptr);

#endif
