/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:24:42 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/07 17:45:49 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_index_for4(char *str)
{
	if ((str = ft_strstr(str, "1111")))
		return (2);
	else
		return (3);
}

int		ft_index_for31(char *str, char *tmp)
{
	char *str2;

	str2 = str;
	if ((str = ft_strstr(str2, "211")))
		return (4);
	else if ((str = ft_strstr(str2, "121")))
		return(13);
	else if ((str = ft_strstr(str2, "112")))
		return (8);
	else if ((str = ft_strstr(tmp, "211")))
		return (7);
	else if ((str = ft_strstr(tmp, "121")))
		return (14);
	else if ((str = ft_strstr(tmp, "112")))
		return (6);
	return (0);
}

int		ft_index_for13(char *str, char *tmp)
{
	char *str2;

	str2 = str;
	if ((str = ft_strstr(str2, "211")))
		return (5);
	else if ((str = ft_strstr(str2, "121")))
		return(15);
	else if ((str = ft_strstr(str2, "112")))
		return (9);
	else if ((str = ft_strstr(tmp, "211")))
		return (11);
	else if ((str = ft_strstr(tmp, "121")))
		return (12);
	else if ((str = ft_strstr(tmp, "112")))
		return (10);
	return (0);
}

int		ft_index_for22(char *str, char *tmp, t_piece *ptr)
{
	char *str2;

	str2 = str;
	if ((str = ft_strstr(str2, "121")))
	{
		if (ft_check_for_two(ptr) == 1)
			return (18);
		else
			return (19);
	}
	else if ((str = ft_strstr(tmp, "121")))
	{
		if (ft_check_for_two(ptr) == 1)
			return (16);
		return (17);
	}
	else if ((str = ft_strstr(ft_strstr(str2, "22"), "22")))
		return (1);
	return (0);
}

void	ft_index(t_piece *ptr)
{
	char *str;
	char *tmp;

	tmp = ft_count_for_sort(ptr);
	if ((str = ft_strstr(tmp, "4")))
		ptr->sort = ft_index_for4(str);
	else if ((str = ft_strstr(tmp, "31")))
		ptr->sort = ft_index_for31(str, tmp);
	else if ((str = ft_strstr(tmp, "13")))
		ptr->sort = ft_index_for13(str, tmp);
	else if ((str = ft_strstr(tmp, "22")))
		ptr->sort = ft_index_for22(str, tmp, ptr);
	ft_putnbr(ptr->sort);
}
