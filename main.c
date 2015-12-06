/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:42:08 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/06 17:06:27 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	fd;
	int	ret;
	char *str;

	fd = 0;
	str = ft_memalloc(100);
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, str, 100);
		ft_putstr(str);
	}
	return (0);
}


