# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 14:30:37 by rdieulan          #+#    #+#              #
#    Updated: 2016/01/08 19:19:17 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	map_get_tetriminos.c\
		map_check_validity.c\
		wrk_fill_node.c\
		res_cross_n_display.c\
		libft/libft.a\
		main.c\
		res_check_n_fill.c\
		tools.c\
		wrk_get_info.c

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	cd libft ; make re ; cd ..
	gcc -o $(NAME) $(FLAG) $(SRC)

clean:
	cd libft ; make clean ; cd ..

fclean: clean
	cd libft ; make fclean ; cd ..
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
