/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:45:14 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/11 17:24:43 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef struct	s_piece
{
	char	**piece;
	char	split;
	struct s_piece	*next;
}				t_piece;

int		**ft_get_coord(t_piece **adr);
void	ft_print_coord(int **tab, t_piece **adr);
char	**ft_buff_to_tab(char *buff);
int		ft_get_tetriminos(int fd, t_piece **lst);
int		ft_check_validity(t_piece *ptr);
char	*ft_count_for_sort(t_piece *ptr);
void	ft_index(t_piece *ptr);
int		ft_check_for_two(t_piece *ptr);
void	ft_lst_push_back(t_piece **lst, char **content, int c);
void	ft_print_list(t_piece **lst, int c);
t_piece	*ft_lst_newi(char **content, int split);

#endif
