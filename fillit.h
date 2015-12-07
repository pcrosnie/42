/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:45:14 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/07 17:29:50 by pcrosnie         ###   ########.fr       */
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
	int		sort;
	struct s_piece	*next;
}				t_piece;

int		ft_check_validity(t_piece *ptr);
char	*ft_count_for_sort(t_piece *ptr);
void	ft_index(t_piece *ptr);
int		ft_check_for_two(t_piece *ptr);

#endif
