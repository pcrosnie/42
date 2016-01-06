# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 14:30:37 by rdieulan          #+#    #+#              #
#    Updated: 2016/01/06 14:33:57 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	ft_get_tetriminos.c\
		ft_check_validity.c\
		ft_search_range.c\
		ft_parkour.c\
		libft.a\
		main.c\
		ft_cruise.c

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAG) $(SRC)

clean:
	/bin/rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
